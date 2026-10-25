class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int> (m , 0));

        queue<pair<int,int>> q;
        int islandColor = grid[row][col];

        q.push({row , col});
        vis[row][col] = 1;

        while(!q.empty()) {
            auto [r , c] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int dr = r + delrow[i];
                int dc = c + delcol[i];
                if(dr < 0 || dc < 0 || dr >= n || dc >= m || vis[dr][dc] || grid[dr][dc] != islandColor) continue;
                vis[dr][dc] = 1;
                q.push({dr , dc});
            }            
        }
        // for(int i = 0 ; i < n ; i++) {
        //     if(vis[i][0]) grid[i][0] = color;
        // }
        // for(int i = 0 ; i < m ; i++) {
        //     if(vis[0][i]) grid[0][i] = color;
        // }

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(vis[i][j]) {
                    if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                        grid[i][j] = color;
                        continue;
                    }

                    for(int k = 0 ; k < 4 ; k++) {
                        int dr = i + delrow[k];
                        int dc = j + delcol[k];
                        if(!vis[dr][dc]) {
                            grid[i][j] = color;
                            break;
                        }
                    }
                }
            }
        }
        


        return grid;
    }
};