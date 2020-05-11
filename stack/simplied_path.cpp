class Solution {
public:
    string simplifyPath(string s) {
      stack<string> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='/')
                continue;
            else if(s[i]=='.')
            {
                if(s[i+1]!='/' and ( i+2<s.size() and s[i+2]!='/') )
                {
                  string r="";
                while(i<s.size() and s[i]!='/')
                {
                    r+=s[i];
                    i++;
                }
                  st.push(r);   
                }
               else if(i+1<s.size() and s[i+1]=='.')
                {   
                    if(!st.empty())
                    st.pop();
                    i++;
                    
                }
            }
            else
            { string r="";
                while(i<s.size() and s[i]!='/')
                {
                    r+=s[i];
                    i++;
                }
             st.push(r);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.empty())
            return "/";
        return ans;
    }
};
