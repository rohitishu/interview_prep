// time complexity-->O(n) spce complexity-->O(n) making two stacks exculding 
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
       stack<int> s1,s2;
        ListNode *temp1=head1,*temp2=head2;
        while(temp1)
        {
            s1.push(temp1->val);
            temp1=temp1->next;
        }
         while(temp2)
        {
            s2.push(temp2->val);
            temp2=temp2->next;
        }
        ListNode *head=NULL,*temp;
        int sum=0,value=0,carry=0;
        while(!s1.empty() || !s2.empty() || carry)
        {    sum=0;
            if(!s1.empty())
            {
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum+=s2.top();
                s2.pop();
            }
            sum+=carry;
            carry=sum/10;
            value=sum%10;
            temp=new ListNode(value);
            if(!head)
               temp->next=NULL;
            if(head)
                temp->next=head;
            head=temp;
        }
        return temp;
    }
};
