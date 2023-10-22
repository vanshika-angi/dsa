bool comp(string&s1, string&s2)
{
    return s1.size()<s2.size();
}
class Solution {
public:
    int helper(int i,int j,vector<string>& words)
    {
        string word1=words[i];
        string word2=words[j];
        
        if(word1.size()!=word2.size() + 1)return false;
        int first=0,second=0;
        
        while(first<word1.size())
        {
            if(second<word2.size() && word1[first]==word2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        
        if(first==word1.size() && second==word2.size())return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(helper(i,j,words) && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
            
            if(dp[i]>maxi)
            {
                maxi=dp[i];
            }
        }
        
        return maxi;
        
    }
};