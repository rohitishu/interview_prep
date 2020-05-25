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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode *temp=head;
        ListNode *p=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int itr=len/k;
        ListNode *join;
        temp=NULL;
        
        while(itr>0)
        {
            ListNode *curr=p;
            ListNode *prev=NULL;
            ListNode *nxt=NULL;
            join=temp;
            int count=0;
            while(curr && count!=k )
            {
                nxt=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
                count++;
                
            }
            temp=p;
            temp->next=curr;
            p=curr;
            if(len/k==itr)
            {
                head=prev;
            }
            else
            {
                join->next=prev;
            }
            
            itr--;
        }
        return head;
    }
};
