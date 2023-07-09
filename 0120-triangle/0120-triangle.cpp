class Solution {
public:
// int m;
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)dp[i][j]=dp[i-1][j] + triangle[i][j];
                else dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,dp[m-1][i]);
        }

        return ans;



        
    }
};


// class Solution {
// public:
// int m;
//     int f(int i,int j,vector<vector<int>>& triangle,int m)
//     {
//         if(i==m-1 )return triangle[i][j];

//         int down=f(i+1,j,triangle,m)+triangle[i][j];
//         int diagnol = f(i+1,j+1,triangle,m) + triangle[i][j];

//         return min(down,diagnol);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//         vector<vector<int>>dp(m,vector<int>)
//         return f(0,0,triangle,m);
//     }
// };