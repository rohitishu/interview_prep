// we can use haspmaps to solve this problem simply we can store the freq of all the letters so that we can remove those letters who are apperaing
// later on while maintaining smallest lexicographically order 
// Time Complexity ---> O(N) Space Complexity---> O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string r;
        unordered_set<char> st;
        unordered_map<char,int> m;
        for(auto i:s)
            m[i]++;
        for(auto x:s)
        {
            m[x]--;
            if(st.find(x)!=st.end())
                continue;
            while(!r.empty() and r[r.size()-1]>x and m[r[r.size()-1]]>0)
            {
                char ch=r[r.size()-1];
                r.pop_back();
                st.erase(ch);
            }
            r+=x;
            st.insert(x);
            
        }
       return r; 
    }
};
