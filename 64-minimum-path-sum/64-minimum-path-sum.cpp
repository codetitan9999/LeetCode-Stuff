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
        vector<int> prev(m),cur(n);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0&&j==0)
                    cur[j]=grid[0][0];
                else {
                int left=1e9,up=1e9;
                if(i>0)
                    up=grid[i][j]+prev[j];
                if(j>0)
                    left=grid[i][j]+cur[j-1];
                cur[j]=min(left,up);
                }
        }
            prev=cur;
        }
        return prev[n-1];
    }
};