typedef struct {
    int top;
    int mintop;
    int *arr;
    int *min;
} MinStack;


MinStack* minStackCreate() {
    MinStack *s = malloc(sizeof(*s));
    s->arr = malloc(sizeof(int)*30000);
    s->min = malloc(sizeof(int)*30000);
    s->top = -1;
    s->mintop = -1;
    return s;
}

void minStackPush(MinStack* obj, int value) {
    obj->arr[++obj->top] = value;
    if(obj->mintop == -1 || value <= obj->min[obj->mintop]){
        obj->min[++obj->mintop] = value;
    }
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->top];
}

void minStackPop(MinStack* obj) {
    if(minStackTop(obj) == obj->min[obj->mintop])obj->mintop--;
    obj->top--;
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->mintop];
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj->min);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/