class Solution {
public:
    // int largestRectangleArea(vector<int>& heights) {
    //   stack<int>st;
    //     int n=heights.size();
    //     vector<int>left(n,0);
    //     vector<int>right(n,0);
       
    //     for(int i=0;i<n;i++)
    //     {
    //       while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            
    //         if(!st.empty())left[i]=st.top()+1;
    //         else left[i]=0;
    //         st.push(i);
    //     }
        
    //     while(!st.empty())st.pop();
       
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            
    //         if(!st.empty())right[i]=st.top()-1;
    //         else right[i]=n-1;
    //         st.push(i);
            
    //     }
    //     int area=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int temp = (right[i]-left[i]+1) * heights[i];
            
    //         area = max(area,temp);
    //     }
        
    //     return area;
    // }

    int largestRectangleArea(vector<int>& heights){
      int n=heights.size();
      stack<int>st;
      int area=0;
      for(int i=0;i<=n;i++)
      {
        
        while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
        {
          int height=heights[st.top()];
          st.pop();
          int width;
          if(st.empty())width=i;
          else width = i-st.top()-1;
          area = max(area, width*height);
        }
        st.push(i);

      }

      return area;
    }
};