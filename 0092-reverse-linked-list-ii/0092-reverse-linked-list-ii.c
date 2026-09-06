/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *pred,*curr,*succ;
    pred = &dummy;
    for(int i=1;i<left;i++){
        pred = pred->next;
    }
    curr = pred->next;
    for(int i=0;i<right-left;i++){
        succ = curr->next;
        curr->next = succ->next;
        succ->next = pred->next;
        pred->next = succ;
    }
    return dummy.next;
}