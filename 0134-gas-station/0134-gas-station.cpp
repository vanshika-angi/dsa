class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0,avail=0,start=0;
        for(int i=0;i<n;i++)
        {
            total = total+gas[i]-cost[i];
            avail = avail+gas[i]-cost[i];
            
            if(avail<0)
            {
                avail=0;
                start = (i+1);
            }
        }
        
        if(total<0)return -1;
        return start;
    }
};