class Solution {
public:
    vector<int> delrow = {0 , 1 , 0 , -1};
    vector<int> delcol = { 1 , 0 , -1 , 0};
    void dfs(int row , int col , vector<vector<int>> & vis , vector<vector<int>> & grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;


        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow < 0 || dcol < 0 || drow >= n || dcol >= m || vis[drow][dcol] || grid[drow][dcol] == 0) continue;
            dfs(drow , dcol , vis , grid);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i , j , vis , grid);
                    cnt++;
                }
            }
        }
        if(cnt == 0 || cnt > 1) return 0;

       
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
               
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    vector<vector<int>> vis2(n , vector<int> (m , 0));
                    int cnt = 0;
                    for(int i = 0 ; i < n ; i++) {
                        for(int j = 0 ; j < m ; j++) {
                            if(grid[i][j] == 1 && !vis2[i][j]) {
                                dfs(i , j , vis2 , grid);
                                cnt++;
                            }
                        }
                    }
                    if(cnt != 1) return 1;
                    grid[i][j] = 1;

                }
            }
        }
        return 2;
    }
};