/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow,*fast;
    for(slow = head,fast = head;fast != NULL && fast->next != NULL;slow = slow->next,fast = fast->next->next){};
    return slow;
}