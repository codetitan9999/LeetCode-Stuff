class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        vector<vector<int>> dist(n , vector<int> (m , 1e8));

        dist[0][0] = 1;
        queue<vector<int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it[0] , col = it[1];
            if(row == n-1 && col == m-1) return dist[row][col];

            for(int i = -1 ; i <= 1 ; i++) {
                for(int j = -1 ; j <= 1 ; j++) {
                    int drow = row + i;
                    int dcol = col + j;

                    if(drow >=0 && drow < n && dcol >=0 && dcol < m && grid[drow][dcol] == 0) {
                        if(dist[drow][dcol] > dist[row][col] + 1) {
                            dist[drow][dcol] = dist[row][col] +1;
                            q.push({drow , dcol});
                        }
                    }
                }
            }


        }
        return -1;
        
    }
};