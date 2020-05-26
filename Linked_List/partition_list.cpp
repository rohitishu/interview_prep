// time complexity--> O(n)  space complexity---> O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::partition(ListNode* head, int x)
{
    if(!head || !head->next)
    return head;
ListNode *head1,*head2,*head3,*head4,*temp;
temp=head;
head1=head2=head3=head4=NULL;
while(temp)
{
    if(temp->val<x)
    {
        if(!head1)
        {
          head1=head2=temp;  
        }
        else
        {
          head2->next=temp; 
          head2=temp;
        }
    }
    else
    {
        if(!head3)
        {
            head3=head4=temp;
        }
        else
        {
            head4->next=temp;
            head4=temp;
        }
        
    }
    temp=temp->next;
}
if(head3)
{
    head4->next=NULL;
    
}
if(head1)
{
    head2->next=head3;
    return head1;
}
return head3;
}
