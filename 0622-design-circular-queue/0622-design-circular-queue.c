


typedef struct {
    int capacity;
    int front;
    int rear;
    int size;
    int* arr;
} MyCircularQueue;

 
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = malloc(sizeof(*q));
    q->capacity = k;
    q->size = 0;
    q->rear = 0;
    q->front = 0;
    q->arr = malloc(sizeof(int)*k);
    return q; 
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return false;
    }
    obj->arr[obj->rear] = value;  
    obj->rear = (obj->rear+1) % obj->capacity;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    obj->front = (obj->front+1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->arr[(obj->rear-1+obj->capacity)%obj->capacity];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/