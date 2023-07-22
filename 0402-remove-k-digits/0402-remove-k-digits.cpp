class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char>st;
        int n=num.length();
        if(n==k)return "0";
        st.push(num[0]);
        for(int i=1;i<n;i++)
        {
            char c = num[i];
            while(!st.empty() && c<st.top() && k>0)
            {
                k--;
                st.pop();
            }
            if(st.empty()==false || c!='0')st.push(c);
            
        }
         while(!st.empty()  && k>0)
            {
                k--;
                st.pop();
            }
        while(!st.empty())
        {
            ans.insert(ans.begin(),st.top());
            st.pop();
        }
        if(ans.length()==0)return "0";
        return ans;
    }
};