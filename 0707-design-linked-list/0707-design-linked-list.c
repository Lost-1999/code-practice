typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(*list));
    list->head = malloc(sizeof(*list->head));
    list->head->next = NULL;
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
    Node *p = obj->head;
    if(index < 0 || index > obj->size)return;
    Node *q = malloc(sizeof(*q));
    for(int i=0;i<index;i++){
        p = p->next;
    }
    q->val = val;
    q->next = p->next;
    p->next = q;
    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj,0,val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj,obj->size,val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    Node *p = obj->head;
    if(index < 0 || index >= obj->size)return;
    for(int i=0;i<index;i++){
        p = p->next;
    }
    Node *q = p->next;
    p->next = q->next;
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