class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
       deque<int> s;
       vector<int> ans;
       for(int i=0;i<k;i++)
       {
       while(!s.empty() and v[i]>=v[s.front()])
       {
       s.pop_back();
       }
       s.push_back(i);
       }
       
       for(int i=k;i<v.size();i++)
       {
       ans.push_back(v[s.front()]);
       if(!s.empty() and s.front()==i-k)
       {
       s.pop_front();
       }
       while(!s.empty() and v[i]>=v[s.front()])
       {
       s.pop_back();
       }
       s.push(i);
       }
       
       ans.push_back(v[s.front()]);
       return ans;
    }
};
