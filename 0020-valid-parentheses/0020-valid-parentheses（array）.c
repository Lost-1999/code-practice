bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    while(*s != '\0'){
        if(*s == '(')stack[++top] = ')';
        else if(*s == '[')stack[++top] = ']';
        else if(*s == '{')stack[++top] = '}';
        else if(*s == ')' || *s == ']' || *s == '}'){
            if(top == -1 || stack[top--] != *s)return false;
        }
        s++;
    }
    return top == -1;
}
