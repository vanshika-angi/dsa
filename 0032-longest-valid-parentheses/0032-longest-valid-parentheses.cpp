class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0,ans=0;
        
        int n=s.length();
        //left to right
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(close>open)
            {
                close=0;
                open=0;
            }
            else if(open==close)
            {
                ans=max(ans,open+close);
            }
        }
        open=0,close=0;
        //right to left
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open>close)
            {
                close=0;
                open=0;
            }
            else if(open==close)
            {
                ans=max(ans,open+close);
            }
        }
        
        return ans;
    }
};