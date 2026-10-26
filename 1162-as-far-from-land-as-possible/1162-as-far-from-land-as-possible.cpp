class Solution {
public:
    vector<int> delrow = { 1 , 0 , -1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e9));

        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    q.push({i , j});
                    dist[i][j] = 0;
                    cnt++;
                }
            }
        }
        if(cnt == n*m || cnt == 0) return -1;
        int time = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [row , col] = q.front();
                q.pop();
                for(int i = 0 ; i < 4 ; i++) {
                    int drow = row + delrow[i];
                    int dcol = col + delcol[i];
                    if(drow < 0 || dcol < 0 || drow >= n || dcol >= m || grid[drow][dcol] == 1 || dist[drow][dcol] != 1e9) {
                        continue;
                    }
                    dist[drow][dcol] = time;
                    q.push({drow , dcol});
                }

            }
            time++;
        }
        return time-1;
    }
};