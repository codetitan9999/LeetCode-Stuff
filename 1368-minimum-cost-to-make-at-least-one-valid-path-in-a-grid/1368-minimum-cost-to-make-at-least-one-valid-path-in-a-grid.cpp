class Solution {
public:
    vector<int> delrow = {0, 0 , 1 , -1};
    vector<int> delcol = {1, -1 , 0 , 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n , vector<int> (m , INT_MAX));

        deque<vector<int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        while(!dq.empty()) {
            int row = dq.front()[0];
            int col = dq.front()[1];
            int dir = grid[row][col];
            dq.pop_front();
            if(row == n-1 && col == m-1) return dist[row][col];

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow >= n || dcol >= m || drow < 0 || dcol < 0) continue;
                if(i+1 == dir) {
                    if(dist[drow][dcol] > dist[row][col] + 0) {
                        dist[drow][dcol] = dist[row][col] + 0;
                        dq.push_front({drow , dcol});
                    }

                } else {

                    if(dist[drow][dcol] > dist[row][col] + 1) {
                        dist[drow][dcol] = dist[row][col] + 1;
                        dq.push_back({drow , dcol});
                    }


                }
            }
        }
        return 0;
        
    }
};