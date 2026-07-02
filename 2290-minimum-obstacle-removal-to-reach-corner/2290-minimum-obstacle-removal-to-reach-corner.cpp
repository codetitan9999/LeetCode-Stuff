class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        dist[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_front({0,0});
        while(!dq.empty()) {
            int row = dq.front().first;
            int col = dq.front().second;
            dq.pop_front();
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow >=0 && dcol >=0 && drow < n && dcol < m) {
                    if(dist[drow][dcol] > (dist[row][col] + grid[drow][dcol])) {
                        dist[drow][dcol] = (dist[row][col] + grid[drow][dcol]);
                        
                        if(grid[drow][dcol] == 0) {
                            dq.push_front({drow, dcol});
                        } else {
                            dq.push_back({drow, dcol});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];

        
        
    }
};