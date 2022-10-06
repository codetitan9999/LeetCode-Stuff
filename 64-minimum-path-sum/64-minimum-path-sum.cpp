class Solution {
public:
    int fun(vector<vector<int>>& grid, int m, int n,vector<vector<int>> & dp) {
        
        if(m==0&&n==0) {
            return grid[0][0];
        }
        if(m<0||n<0)
            return 1e9;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int left=grid[m][n] + fun(grid,m,n-1,dp);
        int up=grid[m][n] + fun(grid,m-1,n,dp);
        
        return dp[m][n]= min(left,up);
        
    }
    int minPathSum(vector<vector<int>>& grid) { 
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(),-1));
        return fun(grid, grid.size()-1, grid[0].size()-1,dp);
    }
};