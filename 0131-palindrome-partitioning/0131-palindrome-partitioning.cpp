class Solution {
public:
    vector<vector<string>>ans;
    
    bool possible(int start,int end, string s)
    {
        int low=start;
        int high=end;
        while(low<=high)
        {
            if(s[low]!=s[high])return false;
            low++;
            high--;
        }
        
        return true;
    }
    void f(int ind,string s,vector<string>&path)
    {
        //base case
        if(ind==s.length())
        {
            ans.push_back(path);
            return;
        }
        
        
        //recursions
        for(int i=ind;i<s.length();i++)
        {
            if(possible(ind,i,s))
            {
                string temp=s.substr(ind,i-ind+1);
                path.push_back(temp);
                f(i+1,s,path);
                
                //backtrack
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<string>path;
        f(0,s,path);
        return ans;
    }
};