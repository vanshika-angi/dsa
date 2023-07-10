class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n=image.size();
       int m=image[0].size();
       queue<pair<int,int>>q;
       vector<vector<int>>vis(n,vector<int>(m,0));

       int oldcolor=image[sr][sc];
       q.push({sr,sc});
       vis[sr][sc]=1;
       image[sr][sc]=color;


       while(!q.empty())
       {
           int row=q.front().first;
           int col=q.front().second;
           q.pop();


           vector<int>delrow{-1,0,1,0};
           vector<int>delcol{0,1,0,-1};

           for(int i=0;i<4;i++)
           {
               int nrow = row+delrow[i];
               int ncol = col+delcol[i];

               if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
               && image[nrow][ncol]==oldcolor && vis[nrow][ncol]==0)
               {
                   vis[nrow][ncol]=1;
                   image[nrow][ncol]=color;
                   q.push({nrow,ncol});
               }
           }
       }

       return image; 
    }
};