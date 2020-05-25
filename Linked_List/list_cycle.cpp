// there are two approach two solve this problem 
// 1. we can store the address of each node whenever we noticed any address is repeated then we can return that cycle is repeated on that node
// time complexity --> O(n) space complexity---> O(n)
// 2. we can use two pointer method to track the cyclis node 
// time complexity --> O(n) space complexity-->O(1)
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   /* if(!head)
    return NULL;
    unordered_set<ListNode *> s;
    while(head)
    {
        if(s.find(head)!=s.end())
        return head;
        s.insert(head);
        head=head->next;
    }
    return NULL;*/
    // optimized code
    ListNode *temp1=head,*temp2=head;
    bool flag=false;
    while(temp1 and temp2)
    {
        temp1=temp1->next;
        if(!temp2->next)
        return NULL;
        temp2=temp2->next->next;
        if(temp1==temp2)
        {
            flag=true;
            break;
        }
    }
     if(!flag)
    return NULL;
    temp1=head;
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}
