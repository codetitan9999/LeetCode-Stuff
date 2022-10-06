class Solution {
public:
    // int fun(vector<vector<int>>& obstacleGrid, int m, int n,vector<vector<int>> &dp) {
    //     if(m>=0&&n>=0&&obstacleGrid[m][n]==1)
    //         return 0;
    //     if(m==0&&n==0)
    //         return 1;
    //     if(m<0||n<0)
    //         return 0;
    //     if(dp[m][n]!=-1)
    //         return dp[m][n];
    //     int left=fun(obstacleGrid,m,n-1,dp);
    //     int up=fun(obstacleGrid,m-1,n,dp);
    //     return dp[m][n]=left+up;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int left=0,up=0;
                if(i>=0&&j>=0&&obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else if(i==0&&j==0)
                    dp[i][j]=1;
                else {
                 
                    if(i>0)
                        up=dp[i-1][j];
                    if(j>0)
                        left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
                
        }
        }
        return dp[m-1][n-1];
    }
};