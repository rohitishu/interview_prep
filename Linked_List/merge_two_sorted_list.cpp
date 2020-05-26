// approach--> apply recursion
// time complexity-->O(n) space complexity--> call stack O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* head1, ListNode* head2) {
   if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    ListNode *head;
    if(head1->val<head2->val)
    {
        head=head1;
        head->next=mergeTwoLists(head1->next,head2);
    }
    else
    {
        head=head2;
        head->next=mergeTwoLists(head1,head2->next);
    }
    return head;
}
