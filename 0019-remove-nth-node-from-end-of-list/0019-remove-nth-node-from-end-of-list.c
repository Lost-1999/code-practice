/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *slow,*fast;
    slow = &dummy;
    fast = &dummy;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *target = slow->next;
    slow->next = target->next;
    free(target);
    return dummy.next;
}