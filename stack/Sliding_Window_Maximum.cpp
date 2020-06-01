// for this approach we use some data structure where we store the result at front of the window every time suppose if we have a window 
// size of 3 we can have answer for first three element at index 0 and so on and whenever we reached max size of window we will remove the 
// front element 
// NOTE:- we never want an element which is smaller than the current element it means whatever the element which are less than on left 
// side of the greater element we can remove them they will never use in any window formed
// for such application where we need both direction back and front --> back for insert new elem. and front for taking max elem in window 
// Time complexity--> O(nk) Space complexity-->O(n)
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
