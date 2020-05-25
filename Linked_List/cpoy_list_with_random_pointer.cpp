/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/
ListNode* clonelist(ListNode *head) {
    //Time Complexity--> O(n) Space Complexity---> O(n) with hashing 
/*if(head==NULL)
return NULL;
ListNode* headnode=new ListNode(head->val);
ListNode* newp=headnode;
ListNode* oldp=head;
unordered_map<ListNode*,ListNode*> m;
m[oldp]=newp;
while(oldp->next)
{
    ListNode* temp=new ListNode(oldp->next->val);
    newp->next=temp;
    m[oldp->next]=newp->next;
    oldp=oldp->next;
    newp=newp->next;
}
newp=headnode;
oldp=head;
while(oldp!=NULL)
{   if(oldp->random==NULL)
         newp->random=NULL;
         else
    newp->random=m[oldp->random];
    oldp=oldp->next;
    newp=newp->next;
}
return headnode;*/

// optimized code space complexity--> O(1) without hashing

// step 1. building new linked list inside existing linked list 
if(!head)
return head;
ListNode *temp=head;
while(temp)
{
    auto curr=new ListNode(temp->val);
    auto forward=temp->next;
    temp->next=curr;
    curr->next=forward;
    temp=forward;
}
// step 2. pointing the random pointer in new linked list with existing linked list
temp=head;
while(temp and temp->next)
{   
    if(temp->random)
    temp->next->random=temp->random->next;
    temp=temp->next->next;
}
// step 3. seperating the new linked list with the existing one
temp=head;
auto curr=temp->next;
auto newhead=curr;
while(temp and temp->next)
{
 temp->next=temp->next->next;
 if(curr->next)
 curr->next=curr->next->next;
 temp=temp->next;
 curr=curr->next;
}
return newhead;
}
