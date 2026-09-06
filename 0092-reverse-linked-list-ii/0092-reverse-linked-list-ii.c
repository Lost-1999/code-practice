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
    struct ListNode *beforel,*l,*r,*afterr;
    beforel = &dummy;
    r = head;
    for(int i=1;i<left;i++){
        beforel = beforel->next;
    }
    l = beforel->next;
    for(int i=1;i<right;i++){
        r = r->next;
    }
    afterr = r->next;
    struct ListNode *pred,*curr,*succ;
    for(pred=afterr,curr=l;curr!=afterr;pred=curr,curr=succ){
        succ = curr->next;
        curr->next = pred;
    }
    beforel->next = pred;
    return dummy.next;
}