void reverseString(char* s, int sSize) {
    char *head = s;
    char *tail = s+sSize-1;
    while(head < tail){
        char temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
}