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
        vector<int> prev(n),cur(n);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int left=0,up=0;
                if(i>=0&&j>=0&&obstacleGrid[i][j]==1)
                    cur[j]=0;
                else if(i==0&&j==0)
                    cur[j]=1;
                else {
                 
                    if(i>0)
                        up=prev[j];
                    if(j>0)
                        left=cur[j-1];
                    cur[j]=left+up;
                }
                
        }
            prev=cur;
        }
        return prev[n-1];
    }
};