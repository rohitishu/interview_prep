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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *temp=head;
        ListNode *start,*end;
        int c=1;
        while(temp)
        {
           if(c==m)
           {
               start=temp;
           }
           if(c==n)
           {
               end=temp;
           }
            temp=temp->next;
            c++;
        }
        ListNode *prev1=NULL;
        if(m>1)
        {
           temp=head;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            prev1=temp;
        }
        ListNode *curr=start;
        ListNode *prev=NULL;
        ListNode *nxt=NULL;
        int m1=m;
        while(curr && m<=n)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            m++;
        }
        start->next=curr;
        if(m1>1)
        {
            prev1->next=prev;
            return head;
        }
        return prev;
   
    }
        
    
};
