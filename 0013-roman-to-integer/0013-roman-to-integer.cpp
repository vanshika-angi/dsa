class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        int ans=0;
        unordered_map<string,int>mp;
        mp["I"]=1;
        mp["V"]=5;
        mp["X"]=10;
        mp["L"]=50;
        mp["C"]=100;
        mp["D"]=500;
        mp["M"]=1000;
        mp["IV"]=4;
        mp["IX"]=9;
        mp["XL"]=40;
        mp["XC"]=90;
        mp["CD"]=400;
        mp["CM"]=900;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='I' || s[i]=='X' || s[i]=='C')
            {
                string val=s.substr(i,2);
                // cout<<val<<endl;
                if(mp.find(val)!=mp.end())
                {
                    ans+=mp[val];
                    i++;
                    continue;
                }
            }
            // cout<<s[i]<<endl;
            string temp = "";
            temp+=s[i];
            ans+=mp[temp];
        }
        
        return ans;
    }
};