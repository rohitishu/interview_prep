// we can reverse the stack using recursion 
// Time COmplexity---> O(N) Space Complexity---> O(N)
void sol(stack<int> &s,vector<int> &v)
{
    if(s.empty()) 
    return ;
    int temp=s.top();
    s.pop();
    sol(s,v);
    v.push_back(temp);
}

vector<int> Solution::solve(vector<int> &v) {
    
      vector<int> ans;
    stack<int> s;
    for(int i=v.size()-1;i>=0;i--)
    {
        s.push(v[i]);
    }
    sol(s,ans);
   return ans;
}
