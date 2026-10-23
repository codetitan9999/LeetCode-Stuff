
class Solution {
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        using State = tuple<int, int, int>;
        queue<State> q;

        vector<vector<vector<bool>>> vis(
            n, vector<vector<bool>>(m, vector<bool>(64, false))
        );

        int keys = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0});
                    vis[i][j][0] = true;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    keys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [row, col, v] = q.front();
                q.pop();

                if (v == keys)
                    return steps;

                for (int i = 0; i < 4; i++) {
                    int drow = row + delrow[i];
                    int dcol = col + delcol[i];

                    if (drow < 0 || dcol < 0 ||
                        drow >= n || dcol >= m ||
                        grid[drow][dcol] == '#')
                        continue;

                    char ch = grid[drow][dcol];

                    // Check if we have the key for this lock
                    if (ch >= 'A' && ch <= 'Z') {
                        int bit = 1 << (ch - 'A');

                        if ((v & bit) == 0)
                            continue;
                    }

                    int newMask = v;

                    // Collect key
                    if (ch >= 'a' && ch <= 'z') {
                        newMask |= (1 << (ch - 'a'));
                    }

                    if (vis[drow][dcol][newMask])
                        continue;

                    vis[drow][dcol][newMask] = true;
                    q.push({drow, dcol, newMask});
                }
            }

            steps++;
        }

        return -1;
    }
};
