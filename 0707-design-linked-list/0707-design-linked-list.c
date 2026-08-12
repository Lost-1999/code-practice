typedef struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(*list));
    list->head = malloc(sizeof(*list->head));
    list->tail = malloc(sizeof(*list->tail));
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->head->prev = NULL;
    list->tail->next = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)return -1;
    Node *p = obj->head->next;
    while(index--){
        p = p->next;
    }
    return p->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size)return;
    Node *pred,*succ;
    if(index <= obj->size/2){
        pred = obj->head;
        for(int i=0;i<index;i++){
            pred = pred->next;
        }
        succ = pred->next;
    }
    else{
        succ = obj->tail;
        for(int i=0;i<obj->size-index;i++){
            succ = succ->prev;
        }
        pred = succ->prev;
    }
    Node *p = malloc(sizeof(*p));
    p->val = val;
    p->next = succ;
    p->prev = pred;
    pred->next = p;
    succ->prev = p;
    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj,0,val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj,obj->size,val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    Node *q;
    if(index < 0 || index >= obj->size)return;
    if(index <= obj->size/2){
        q = obj->head->next;
        for(int i=0;i<index;i++){
            q = q->next;
        };
    }
    else{
        q = obj->tail->prev;
        for(int i=0;i<obj->size-1-index;i++){
            q = q->prev;
        }
    }
    q->prev->next = q->next;
    q->next->prev = q->prev;
    free(q); 
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *p = obj->head;
    while(p != NULL){
        Node *q = p->next;
        free(p);
        p = q;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/