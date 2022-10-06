class Solution {
public:
//     int fun(vector<vector<int>>& grid, int m, int n,vector<vector<int>> & dp) {
        
//         if(m==0&&n==0) {
//             return grid[0][0];
//         }
//         if(m<0||n<0)
//             return 1e9;
//         if(dp[m][n]!=-1)
//             return dp[m][n];
//         int left=grid[m][n] + fun(grid,m,n-1,dp);
//         int up=grid[m][n] + fun(grid,m-1,n,dp);
        
//         return dp[m][n]= min(left,up);
        
//     }
    int minPathSum(vector<vector<int>>& grid) { 
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0&&j==0)
                    dp[i][j]=grid[0][0];
                else {
                int left=1e9,up=1e9;
                if(i>0)
                    up=grid[i][j]+dp[i-1][j];
                if(j>0)
                    left=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(left,up);
                }
        }
        }
        return dp[m-1][n-1];
    }
};