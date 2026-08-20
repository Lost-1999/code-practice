/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *p = &dummy;
    while(list1 && list2){
        if(list1->val <= list2->val){
            p->next = list1;
            list1 = list1->next;
        }
        else{
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    p->next = list1 ? list1 : list2;
    return dummy.next;
}
