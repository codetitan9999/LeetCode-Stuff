class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int dfs(int row , int col , vector<vector<int>>& grid , vector<vector<int>> & vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int ans = 0;
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow < 0 || dcol < 0 || drow >= n || dcol >= m || grid[drow][dcol] == 0 || vis[drow][dcol]) continue;
            ans = max(ans ,  dfs(drow , dcol , grid , vis));
        }
        vis[row][col] = 0;
        return grid[row][col] + ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int> ( m , 0));
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] != 0) {
                    ans = max(ans , dfs(i , j , grid , vis));
                }
            }
        }
        return ans;


        
    }
};