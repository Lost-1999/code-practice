/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL || head->next == NULL)return NULL;
    struct ListNode *slow,*mid,*fast;
    slow = head;
    mid = head;
    fast = head;
    for(int i=0;i<n-1;i++){
        fast = fast->next;
    }
    if(fast->next != NULL){
        fast = fast->next;
        mid = mid->next;
    }
    else{
        return head->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        mid = mid->next;
        slow = slow->next;
    }
    slow->next = mid->next;
    free(mid);
    return head;
}