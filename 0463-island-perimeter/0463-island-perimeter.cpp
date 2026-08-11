class Solution {
public:
    vector<int> delrow = {-1 , 1 , 0 , 0};
    vector<int> delcol = {0 , 0 , 1 , -1};
    int dfs(int row , int col , vector<vector<int>> & vis , vector<vector<int>>& grid) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) return 1;

        if(vis[row][col] == 1) return 0;
        
        vis[row][col] = 1;
        int ans = 0;
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row+ delrow[i];
            int dcol = col + delcol[i];
            ans += dfs(drow , dcol , vis , grid);
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int> (m , 0));


        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    return dfs(i , j , vis , grid);
                }
            }
        }
        return 0;

        
    }
};