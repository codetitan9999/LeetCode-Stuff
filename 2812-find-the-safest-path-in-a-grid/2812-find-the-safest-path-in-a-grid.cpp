class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1  , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> mat(n , vector<int> (m , 1e9));
        queue<pair<int,int>> q;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    q.push({i , j});
                    mat[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto [row , col] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >= n || dcol >= m || mat[drow][dcol] != 1e9) continue;

                mat[drow][dcol] = 1 + mat[row][col];
                q.push({drow , dcol});
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> dist(n , vector<int> (m , INT_MIN));

        dist[0][0] = mat[0][0];
        pq.push({dist[0][0] , 0 , 0});

        while(!pq.empty()) {
            auto [d , row , col] = pq.top();
            pq.pop();
            if(dist[row][col] != d) continue;
            if(row == n-1 && col == m-1) return d;
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >= n || dcol >= m ) continue;
                int newVal = min(d , mat[drow][dcol]);
                if(newVal > dist[drow][dcol]) {
                    dist[drow][dcol] = newVal;
                    pq.push({newVal , drow , dcol});
                }
            }
        }
        return 0;


        
    }
};