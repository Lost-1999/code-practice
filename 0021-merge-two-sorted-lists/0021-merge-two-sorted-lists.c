/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *p,*head = NULL ,*tail = NULL;
    while(list1 != NULL && list2 != NULL){
        p = list1->val <= list2->val ? list1 : list2;
        if(list1->val <= list2->val){
            list1 = list1->next;
        }else{
            list2 = list2->next;
        }
        if(head == NULL){
            head=p;
        }else{
            tail->next = p;
        }
        tail = p;
    }
    if(tail != NULL)tail->next = list1 != NULL ? list1 : list2;
    else head = list1 != NULL ? list1 : list2;
    return head; 
}