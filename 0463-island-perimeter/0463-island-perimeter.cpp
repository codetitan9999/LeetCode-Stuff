class Solution {
public:
    vector<int> delrow = {-1 , 0 ,1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int f(int row , int col, vector<vector<int>> & grid , vector<vector<int>> & vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int ans = 0;

        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow <0 || dcol < 0 || drow >=n || dcol >= m || grid[drow][dcol] == 0) {
                ans += 1;
                continue;
            } else if(!vis[drow][dcol]){
                ans += f(drow , dcol , grid , vis);
            }

        }
        return ans;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int> (m , 0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(!vis[i][j] & grid[i][j] == 1) {
                    return f(i , j , grid , vis);
                }
            }
        }
        return 0;


        
    }
};