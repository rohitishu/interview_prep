//this problem is same as valid parathesis problem just we need to calculate the longest one valid parenthesis length 
//here we can apply the stack data structure and and we know that from valid parenthesis prob that if a stack is empty it means
// it has valid parenthesis so push the element for '(' and cal. the lenght for char ')'  
// time complexity --->O(n) space complexity-->O(n)
int Solution::longestValidParentheses(string str) {
    stack<int> s;
    s.push(-1);
    int n=str.size();
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        s.push(i);
        else
        {
            s.pop();
            if(!s.empty())
            maxi=max(maxi,i-s.top());
            else
            s.push(i);
        }
    }
    return maxi;
}
