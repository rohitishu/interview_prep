// we can solve the reverse polish notation problem using stack we can store operands till the operators doesn't come 
//Time Complexity-->O(n) Space Complexity-->O(n)
class Solution {
public:
    int evalRPN(vector<string>& v) {
     stack<int> s;
    for(int i=0;i<v.size();i++)
    {
        string str=v[i];
        stringstream iss(str);
        int x=0;
        iss>>x;
        if(v[i]=="+" || v[i]=="-" || v[i]=="/" || v[i]=="*" || v[i]=="^")
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            int res=perform(v[i],op1,op2);
            s.push(res);
        }
        else
        {
            s.push(x);
        }
    }
    return s.top();
    }
int perform(string str,int op1,int op2)
{ int ans;
    if(str=="+")
     ans=op1+op2;
    if(str=="-")
     ans=op1-op2;
    if(str=="*")
    ans=op1*op2;
    if(str=="/")
     ans=op1/op2;
 return ans;
}
    
};
