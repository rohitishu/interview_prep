//we can use stack for this problem. Here we need to find maximum histogram rectangle for that we need to find the minimum height
// minimum height because it can cover all the heights below it so we can calculate the total area
// suppose we have 2,1,5,6,2,3---> we can push all the number till we don't find number smaller number tham top of the stack 
// Time Complexity---> O(N) Space Complexity----> O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
    
     stack<int> s;
        int n=v.size();
        if(n==0)
            return 0;
        s.push(0);
        int area=0,maxi=INT_MIN,i;
        for( i=1;i<n;i++)
        {
            while(!s.empty() and v[i]<v[s.top()])
            {
                int d=v[s.top()];
                s.pop();
                if(s.empty())
                {
                    area=d*i;
                }
                else
                {
                    area=d*(i-1-s.top());
                }
                maxi=max(maxi,area);
            }
            s.push(i);
        }
        while(!s.empty())
        {
           int d=v[s.top()];
                s.pop();
                if(s.empty())
                {
                    area=d*i;
                }
                else
                {
                    area=d*(i-1-s.top());
                }
                maxi=max(maxi,area);  
        }
        return maxi;
    }
};
