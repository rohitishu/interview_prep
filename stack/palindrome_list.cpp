    ListNode* reverse(ListNode *head)
    {
    int len=0;
    ListNode *temp=head;
    while(temp)
    {
    len++;
    temp=temp->next;
    }
    ListNode *curr=head,*prev=NULL,*nxt=NULL;
    int m=1,n=len/2;
    while(curr and m<=n)
    {
    nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=prev;
    m++;
    }
    ListNode *start;
    head->next=curr;
    start=curr;
    if(len%2!=0)
    start=start->next;
    temp=prev;
    while(temp and start)
    {
    if(temp->val1=start->val)
    return false;
    start=start->next;
    temp=temp->next;
    }
    return true;
    }
