// Time Complexity---> O(N) Space Complexity---->O(N)
// problem is same as largest area in histogram / maximum rectangle
vector<int> Solution::prevSmaller(vector<int> &v) {
    vector<int> ans;
    int arr[v.size()];
    if(v.size()==1)
    {
        ans.push_back(-1);
        return ans;
    }
    stack<int> s;
    s.push(v.size()-1);
    for(int i=v.size()-2;i>=0;i--)
    {
        while(!s.empty() && v[s.top()]>v[i])
        {
            int d=s.top();
            s.pop();
            arr[d]=v[i];
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int d=s.top();
        s.pop();
        arr[d]=-1;
    }
        for(int i=0;i<v.size();i++)
    ans.push_back(arr[i]);
    return ans;
}
