/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) { 
    struct ListNode *prev,*curr,*succ;
    for(prev = NULL,curr = head;curr != NULL;prev = curr,curr = succ){
        succ = curr->next;
        curr->next = prev;
    }
    return prev;
}