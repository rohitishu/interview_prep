int Solution::solve(vector<int> &A)
{
stack<int> s1,s2;
int n=A.size();
for(int i=0;i<n;i++)
{
while(!s2.empty() and s2.top()<A[i])
{
if(s1.empty() and s1.top()<s2.top())
{
s1.push(s2.top());
s2.pop();
}
else
return 0;
}
s2.push(A[i]);
}
while(!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
sort(A.begin(),A.end());
for(int i=0;i<n;i++)
{
if(A[i]!=s2.top())
return 0;
s2.pop();
}
return 1;
}
