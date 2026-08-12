typedef struct{
    int top;
    int capacity;
    char *arr;
}Stack;
Stack* Create(int maxsize){
    Stack *s;
    s = malloc(sizeof(*s));
    s->arr = malloc(sizeof(char)*maxsize);
    s->capacity = maxsize;
    s->top = -1;
    return s;
}
bool IsEmpty(Stack *s){
    return s->top == -1;
}
void push(Stack *s,char c){
    s->arr[++s->top] = c;
}
void pop(Stack *s){
    s->top--;
}
char top(Stack *s){
    return s->arr[s->top];
}
void Dispose(Stack *s){
    free(s->arr);
    free(s);
}
bool isValid(char* s) {
    Stack* stack = Create(strlen(s));
    while(*s != '\0'){
        if(*s == '(' || *s == '[' || *s == '{'){
            push(stack,*s);
        }
        else if(*s == ')' || *s == ']' || *s == '}'){
            if(IsEmpty(stack)){
                Dispose(stack);
                return false;
            }
            char c = top(stack);
            if(*s == ')' && c == '(' ||
               *s == ']' && c == '[' ||
               *s == '}' && c == '{'){
                pop(stack);
            }
            else{
                Dispose(stack);
                return false;
            }
        }
        s++;
    }
    bool result = IsEmpty(stack);
    Dispose(stack);
    return result;
}
