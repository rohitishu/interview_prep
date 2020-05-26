// time complexity--> O(n) space complexity-->O(1) exclude making new linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        ListNode *newhead=NULL,*head;
        int sum=0,carry=0,value=0;
        ListNode *temp1=head1,*temp2=head2;
        while(temp1 or temp2 or carry)
        {   sum=0;
             if(temp1)
             {
                 sum+=temp1->val;
                 temp1=temp1->next;
             }
              if(temp2)
             {
                 sum+=temp2->val;
                 temp2=temp2->next;
             }
           sum+=carry;
            carry=sum/10;
            value=sum%10;
            ListNode *temp=new ListNode(value);
            if(newhead==NULL)
            {
                newhead=temp;
                head=newhead;
            }
            else
            {
                newhead->next=temp;
                newhead=temp;
            }
           
            
            
        }
        return head;
    }
};
