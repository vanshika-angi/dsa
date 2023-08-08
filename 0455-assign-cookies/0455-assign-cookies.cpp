class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        for(int i=0;cnt<g.size() && i<s.size();i++)
        {
            if(s[i]>=g[cnt])
            {
                cnt++;
            }
        }
        return cnt;
    }
};