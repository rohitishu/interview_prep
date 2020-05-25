   bool isPalindrome(ListNode* head) {
        
       if(!head || !head->next)    return true;
    ListNode *temp=head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int m=1,n=len/2;
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *nxt=NULL;
        while(curr && m<=n)
        {
          nxt=curr->next;
          curr->next=prev;
            prev=curr;
            curr=nxt;
            m++;
        }
        ListNode *start;
        head->next=curr;
        start=curr;
        if(len%2!=0)
        {
           start=start->next; 
        }
        temp=prev;
        while(temp && start)
        {
            if(start->val!=temp->val)
                return false;
            start=start->next;
            temp=temp->next;
        }
        return true;
    }
};
