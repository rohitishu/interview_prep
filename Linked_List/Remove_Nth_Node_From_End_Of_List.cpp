// approach is simple just count number of of list and traverse it whenever you encounter that position just delete that node
// time complexity--> O(n) space complexity--->O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *root=head;
        int count=0;
        while(root)
        {
            root=root->next;
            count++;
        }
        root=head;
        n=count-n;
         count=0;
        ListNode *prev=NULL;
        while(root && count!=n)
        {
            prev=root;
            root=root->next;
            count++;
        }
        if(n==0)
        {
            ListNode *newhead=head;
            head=newhead->next;
            delete newhead;
            return head;
        }
        prev->next=root->next;
        return head;
    }
};
