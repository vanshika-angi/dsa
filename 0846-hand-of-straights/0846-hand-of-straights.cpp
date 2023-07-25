class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return 0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)pq.push(hand[i]);
        
        while(!pq.empty())
        {
            int prev=-1;
            vector<int>tmp;
            for(int i=0;i<groupSize;i++)
            {
                int el=pq.top();
                pq.pop();
                if((i==0)  || el==prev+1)
                {
                    prev=el;
                    continue;
                }
                else
                {
                    while(!pq.empty() && el==prev)
                    {
                        tmp.push_back(el);
                        el=pq.top();
                        pq.pop();
                    }

                    if(el!=prev+1 || pq.empty())
                    {
                        return false;
                    }
                    prev=el;
                }  
            }
            for(auto x:tmp)
            {
                pq.push(x);
            }
            
        }
        return true;
    }
};