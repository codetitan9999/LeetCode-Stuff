class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n , vector<int> (m , 0));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '*') {
                    q.push({i , j});
                    vis[i][j] = 1;
                    break;
                }
            }
        }
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(grid[row][col] == '#') return ans;

                for(int i = 0 ; i < 4 ; i++) {
                    int drow = row + delrow[i];
                    int dcol = col + delcol[i];
                    if(drow >= n || drow < 0 || dcol >=m || dcol < 0 || vis[drow][dcol] || grid[drow][dcol] == 'X') continue;

                    q.push({drow , dcol});
                    vis[drow][dcol] = 1;
                }
            } 
            ans++;
        }
        return -1;
    }
};