class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        deque<pair<int, int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int cost = grid[nrow][ncol];

                    if (dist[row][col] + cost < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dist[row][col] + cost;

                        if (cost == 0) {
                            dq.push_front({nrow, ncol});
                        } else {
                            dq.push_back({nrow, ncol});
                        }
                    }
                }
            }
        }

        return dist[n - 1][m - 1] < health;
    }
};