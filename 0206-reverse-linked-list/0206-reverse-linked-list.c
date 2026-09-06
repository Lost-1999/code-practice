/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) { 
    if(head == NULL)return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *pred,*curr,*succ;
    pred = &dummy;
    curr = pred->next;
    while(curr->next != NULL){
        succ = curr->next;
        curr->next = succ->next;
        succ->next = pred->next;
        pred->next = succ;
    }
    return dummy.next;
}