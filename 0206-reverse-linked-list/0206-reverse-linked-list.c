/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) { 
    struct ListNode *NewHead = NULL;
    struct ListNode *p;
    while(head != NULL){
        p = head->next;
        head->next = NewHead;
        NewHead = head;
        head = p;
    }
    return NewHead;
}