class Solution {
public:
    void dfs(int row , int col , vector<vector<int>> & mat , vector<vector<int>> & vis) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vis[row][col] = 1;
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow>=0 && dcol>=0 && drow<n && dcol<m && vis[drow][dcol] == 0 && mat[drow][dcol] == 0) {
                dfs(drow,dcol,mat,vis);
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0 ; i < n ;i++) {
            for(int j = 0 ; j < m ; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 0) {
                    dfs(i,j,grid,vis);
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ;i++) {
            for(int j = 0 ; j < m ; j++) {
               if(vis[i][j] ==0 && grid[i][j] ==0) {
                   cnt++;
                   dfs(i,j,grid,vis);
               }
            }
        }
        return cnt;
        

    }
};