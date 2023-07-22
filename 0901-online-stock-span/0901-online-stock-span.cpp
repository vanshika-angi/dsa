class StockSpanner {
public:
    stack<pair<int,int>>st;
    int timer=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
       if(st.empty())
       {
           st.push({price,timer});
           timer++;
       }
        else
        {
            while(!st.empty() && st.top().first<=price)st.pop();
            
            int ind=-1;
            if(!st.empty())
            {ind =st.top().second;}
            st.push({price,timer});
            int ans=timer-ind;
            timer++;
            return ans;   
        }
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */