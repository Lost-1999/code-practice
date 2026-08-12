typedef struct{
    int top;
    char *arr;
}Stack;
Stack* Create(){
    Stack *s;
    s = malloc(sizeof(*s));
    s->arr = malloc(sizeof(char)*10000);
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
bool isValid(char* s) {
    Stack* stack = Create();
    while(*s != '\0'){
        if(*s == '(' || *s == '[' || *s == '{'){
            push(stack,*s);
        }
        else if(*s == ')' || *s == ']' || *s == '}'){
            if(IsEmpty(stack))return false;
            else{
                if(*s == ')'){
                    if(stack->arr[stack->top] != '(')return false;
                    else pop(stack);
                }
                if(*s == ']'){
                    if(stack->arr[stack->top] != '[')return false;
                    else pop(stack);
                }
                if(*s == '}'){
                    if(stack->arr[stack->top] != '{')return false;
                    else pop(stack);
                }
            }
        }
        s++;
    }
    if(!IsEmpty(stack))return false;
    else return true;
}