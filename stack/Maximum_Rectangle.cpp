//this problem is same as largetst histogram area problem you jus need to take row-wise area till the last row 
// Time Complexity-->O(M*N*N) Space Complexity-->O(M*N*N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& v) {
    
         if(v.size()==0)
         return 0;
         int m=v.size();
        int n=v[0].size();
        vector<int> ans(n,0);
        int area=0,maxi=INT_MIN;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
              ans[j]=(v[i][j]=='0')?0:ans[j]+1; 
           }
           stack<int> s;
           s.push(0);
           int k;
           for(k=1;k<ans.size();k++)
           {
               while(!s.empty() and ans[k]<ans[s.top()])
               {
                   int d=ans[s.top()];
                   s.pop();
                   if(s.empty())
                       area=d*k;
                   else
                       area=d*(k-1-s.top());
               maxi=max(maxi,area);
               }
               s.push(k);
           }
           while(!s.empty())
           {
            int d=ans[s.top()];
                   s.pop();
                   if(s.empty())
                       area=d*k;
                   else
                       area=d*(k-1-s.top());
               maxi=max(maxi,area);   
           }
           
       }
        return maxi;
        
    }
};
