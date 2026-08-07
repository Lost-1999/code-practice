

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p;
    int i;
    for(i=0,p=obj->next;i<index && p!=NULL;i++,p=p->next){};
    if(i != index)return -1;
    else{
        return p == NULL ? -1 : p->val;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = malloc(sizeof(MyLinkedList));
    p->next = obj->next;
    p->val = val;
    obj->next = p;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj,*q = malloc(sizeof(MyLinkedList));
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
    q->val = val;
    q->next = NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p,*q = malloc(sizeof(MyLinkedList));
    int i;
    for(i=0,p=obj;i<index && p!=NULL;i++,p=p->next){};
    if(i != index)return;
    else{
        q->next = p->next;
        p->next = q;
        q->val = val;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *p,*q;
    int i;
    for(i=0,p=obj;i<index && p->next !=NULL;i++,p=p->next){};
    if(i != index || p->next == NULL)return;
    else{
        q = p->next;
        p->next = q->next;
        free(q);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *p;
    while(obj->next != NULL){
        p = obj;
        obj = obj->next;
        free(p);
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