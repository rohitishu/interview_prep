// ---------Basic of BST-------------
// Building of BST
//Traverse of BST
//Height of BST
//Searching in BST
//Find Max and Min in BST
//Delete a Node in BST
//traverse level order(recursively and iteratively)
//check BT is BST
// -----------time complexity-----------
// insertion and searching --->O(height)-->O(log(n))
//traversing --->O(n)
//find min and max ---> O(n) in case of skew tree otherwise O(height)
//deletion --->O(n) in case of skew tree otherwise O(height)
// checking bst --->O(n) in case of skew tree otherwise O(height)
#include <bits/stdc++.h>
using namespace std;
struct treenode
{
   int val;
   treenode *left,*right;
};
treenode *getnewnode(int data)
{
    treenode *newroot=new treenode();
    newroot->val=data;
    newroot->left=newroot->right=NULL;
    return newroot;
}
//inserting nodes
treenode *insert(treenode *root,int data)
{
    
    if(!root)
    root=getnewnode(data);
    else if(root->val>=data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    return root;
    
}
//Height of BST
int height(treenode *root)
{
    if(!root)
    return -1;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
//searching in BST
bool search(treenode *root,int x)
{
    if(!root)
    return false;
    if(root->val==x)
    return true;
    if(root->val>x)
    return search(root->left,x);
    return search(root->right,x);
}
//inorder traversing
void inorder(treenode *root)
{
  if(!root)
  return ;
  inorder(root->left);
  cout<<root->val<<" ";
  inorder(root->right);
}
//maximum node inside BST
treenode *maxi(treenode *root)
{
    if(!root->right)
    return root;
    maxi(root->right);
    
}
// minimum node inside BST
treenode *mini(treenode *root)
{
    if(!root->left)
    return root;
    mini(root->left);
    
}
// delete an element inside BST
treenode *Delete(treenode *root,int x)
{
    if(!root)
    return NULL;
    if(root->val>x)
    root->left=Delete(root->left,x);
    else if(root->val<x)
    root->right=Delete(root->right,x);
    else
    {
        if(!root->left and !root->right)
        {
           delete root;
           root= NULL;
        }
        else if(!root->left)
        {
            treenode *temp=root;
            root=root->right;
            delete temp;
        }
        else if(!root->right)
        {
           
            treenode *temp=root;
            root=root->left;
            delete temp; 
        }
        else
        {
          treenode *temp=mini(root->right);
          root->val=temp->val;
          root->right=Delete(root->right,temp->val);
        }
        return root;
    }
}
//level order iteratively
void level_iterative(treenode *root)
{  
    if(!root)
    return ;
    queue<treenode *> q;
    q.push(root);
    while(!q.empty())
    {
        treenode *temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    cout<<endl;
    
}
// level order recursively
void level_recursive(treenode *root,int &count,int level)
{
    if(!root)
    return ;
    if(count==level)
    {
        cout<<root->val<<" ";
        
    }
    level_recursive(root->left,count,level+1);
    level_recursive(root->right,count,level+1);
}
bool check(treenode *root,int min_val,int max_val)
{
    if(!root)
    return true;
    if(root->val>min_val and root->val<max_val and check(root->left,min_val,root->val) and check(root->right,root->val,max_val))
    return true;
    return false;
}
// BST check
bool isbst(treenode *root)
{
    return check(root,INT_MIN,INT_MAX);
}
int main()
{
// building a BST
treenode *root=NULL;
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,17);
// traversing the BST using inorder traversing (recursively)
    inorder(root);
// height of the tree
cout<<endl<<"The height of the tree is "<<height(root)<<endl;
// seaching in BST
int x;
cout<<"enter the node you want to search"<<endl;
cin>>x;
if(search(root,x))
cout<<"node is present inside the bst"<<endl;
else
cout<<"node is not present inside the bst"<<endl;
// maximum node inside bst
cout<<"maximum node inside bst "<<maxi(root)->val<<endl;
// minimum node inside bst
cout<<"minimum node inside bst "<<mini(root)->val<<endl;
// delete an element in BST
int dl;
cout<<"enter the element you want to delete"<<endl;
cin>>dl;
Delete(root,dl);
inorder(root);
cout<<endl;
//level order 
cout<<"level order"<<endl;
level_iterative(root);
int n=height(root);
for(int i=0;i<=n;i++)
{
level_recursive(root,i,0);
}
cout<<endl;
// BST check
if(isbst(root))
cout<<"the given binary tree is a bst"<<endl;
else
cout<<"the given binary tree is not a bst"<<endl;
    return 0;
}

