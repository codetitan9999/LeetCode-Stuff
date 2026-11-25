
class Solution {
public:

    pair<int,int> f1(int num, int n) {
        num--;

        int r = num / n;
        int c = num % n;

        if(r % 2 == 1)
            c = n - 1 - c;

        r = n - 1 - r;

        return {r, c};
    }

    int f2(int row, int col, int n) {
        row = n - 1 - row;

        if(row % 2 == 1)
            col = n - 1 - col;

        return row * n + col + 1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<pair<int,int>> q;
        q.push({n - 1, 0});

        vis[n - 1][0] = 1;

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [row, col] = q.front();
                q.pop();

                int num = f2(row, col, n);

                if(num == n * n)
                    return steps;

                for(int i = 1; i <= 6; i++) {
                    int adjNum = num + i;

                    if(adjNum > n * n)
                        break;

                    auto [drow, dcol] = f1(adjNum, n);

                    if(board[drow][dcol] != -1) {
                        adjNum = board[drow][dcol];
                    }

                    auto [nr, nc] = f1(adjNum, n);

                    if(vis[nr][nc])
                        continue;

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

            steps++;
        }

        return -1;
    }
};
