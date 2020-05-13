//solvong this problem have two aproach 
// 1. using stack 
// we can store the char untill we dont encounter ')' bracket after that will pop out all the element till '(' bracket
// Time Complexity--->O(N) Space Complexity-->O(N)
int Solution::braces(string str)
{
stack<char> s;
for(auto x:str)
{
if(x==')')
{
char d=s.top();
s.pop();
int temp=1;
while(d!='(')
{
d=s.top();
s.pop();
temp=0;
}
if(temp==1)
return 1;
}
else
s.push(x);
}
return 0;
}
// 2. we can optimize the code using O(1) space 
// just calculate the '(' baracket and operator if the bracket is greater than operator than we have redudant braces ohterwise not
// intitution behing is this every operator has one open bracket of there is more than one bracket for one operator then there will redudancy
int Solution::braces(string str) {
    // constant space complexity solution 
    int n=str.size();
    int operands=0,braces=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(' && str[i+2]==')')
        return 1;
        if(str[i]=='+' || str[i]=='*' || str[i]=='-' || str[i]=='/')
        operands++;
        if(str[i]=='(')
        braces++;
    }
    if(braces>operands)
    return 1;
    return 0;
    }
