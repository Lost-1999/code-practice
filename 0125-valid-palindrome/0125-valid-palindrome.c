bool isPalindrome(char* s) {
    char *slow = s;
    int len = 0;
    for(char *fast = s;*fast != '\0';fast++){
        if('a' <= *fast && *fast <= 'z'){
            *slow++ = *fast;
        }
        if('A' <= *fast && *fast <= 'Z'){
            *slow++ = *fast-'A'+'a';
        }
        if('0' <= *fast && *fast <='9'){
            *slow++ = *fast;
        }
    }
    char *head,*tail;
    for(head = s,tail = slow-1;head < tail;head++,tail--){
        if(*head != *tail){
            return false;
        }
    }
    return true;
}