vector<int> Solution::solve(vector<int> &v)
{
vector<int> ans;
while(!v.empty())
{
int d=v.back();
v.pop_back();
while(!ans.empty() and d>ans.back())
{
int t=ans.back();
ans.pop_back();
v.push_back(t);
}
ans.push_back(d);
}
reverse(ans.begin(),ans.end());
return ans;
}
