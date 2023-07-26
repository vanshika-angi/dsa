// bool cmp(pair<char, int>& a, pair<char, int>& b) { return a.first > b.first; }
// class Solution {
// public:
//     string frequencySort(string s) {
//         string ans;
//         // priority_queue<pair<int,char>>pq;
//         vector<pair<int,char>>vec;
//         map<char,int>count;
//         for(int i=0;i<s.length();i++)
//         {
//             count[s[i]]++;
//         }
//         for(auto x:count)
//         {
//             vec.push_back({x.second,x.first});
//         }
        
//         sort(vec.begin(),vec.end(),cmp);
//         for(int i=0;i<vec.size();i++)
//         {
//             auto it=vec[i];
//             for(int j=0;j<it.first;j++)ans=ans+it.second;
//         }
        
//         return ans;
//     }
// };

bool cmp(pair<char, int>& a, pair<char, int>& b) { return a.second > b.second; }

class Solution {
 public:
  string frequencySort(string s) {
    string res = "";
    vector<int> a(150, 0);
    vector<pair<char, int>> freq;
    for (auto i : s) {
      a[i - 0]++;
    }
    for (int i = 0; i < 150; i++) {
      if (a[i] > 0) {
        freq.push_back({(char)i, a[i]});
      }
    }
    sort(freq.begin(), freq.end(), cmp);
    for (auto i : freq) {
      for (int j = 0; j < i.second; j++) {
        res += i.first;
      }
    }
    return res;
  }
};
