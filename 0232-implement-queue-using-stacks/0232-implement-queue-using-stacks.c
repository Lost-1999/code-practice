typedef struct {
    int top;
    int capacity;
    int *arr;
} MyStack;

MyStack* myStackCreate() {
    MyStack *s = malloc(sizeof(*s));
    s->top = -1;
    s->capacity = 100;
    s->arr = malloc(sizeof(int)*s->capacity);
    return s;
}

typedef struct {
    MyStack *s1;
    MyStack *s2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(*q));
    q->s1 = myStackCreate();
    q->s2 = myStackCreate();
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->s1->top == -1)obj->s1->arr[++obj->s1->top] = x;
    else{
        while(obj->s1->top != -1){
            obj->s2->arr[++obj->s2->top] = obj->s1->arr[obj->s1->top--]; 
        }
        obj->s1->arr[++obj->s1->top] = x;
        while(obj->s2->top != -1){
            obj->s1->arr[++obj->s1->top] = obj->s2->arr[obj->s2->top--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    return obj->s1->arr[obj->s1->top--];
}

int myQueuePeek(MyQueue* obj) {
    return obj->s1->arr[obj->s1->top];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->s1->top == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1->arr);
    free(obj->s2->arr);
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/