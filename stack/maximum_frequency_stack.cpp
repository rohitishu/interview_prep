unordered_map<int,int> m;
unordered_map<int,stack<int>> m1;
int maxi=0;
void push(int x)
{
    maxi=max(maxi,++m[x]);
    m1[m[x]].push(x);
}
int pop()
{
    int ans=m1[maxi].top();
    m1[maxi].pop();
    --m[ans];
    if(m1[maxi].empty())
    maxi--;
    return ans;
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> v(A.size());
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0]==1)
        {
            push(A[i][1]);
             v[i]=-1; 
        }
        else
        {
         v[i]=pop(); 
        }
        
    }
    m.clear();
    m1.clear();
    maxi=0;
    return v;
}
