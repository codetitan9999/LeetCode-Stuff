class Solution {
public:
    vector<int> delrow = {0 , 1 , 0 , -1};
    vector<int> delcol = {-1 , 0 , 1 , 0};
    int f(int row , int col , vector<vector<int>>& grid , int tot , int visited ,  vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[row][col] == 2) {
            return (tot == visited);
        }
        vis[row][col] = 1;
        int ans = 0;
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow >= n || drow < 0 || dcol <0 || dcol >=m || vis[drow][dcol] || grid[drow][dcol] == -1) continue;
            ans += f(drow , dcol , grid ,tot , visited+1 , vis);
        }
        vis[row][col] = 0;
        return ans;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis( n , vector<int> (m , 0));
        int row = 0 , col = 0;
        int tot = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] != -1) {
                    tot++;
                }
                if(grid[i][j] == 1) {
                    row = i ;
                    col = j;
                }
            }
        }
        return f(row , col , grid ,tot , 1, vis);
        
    }
};