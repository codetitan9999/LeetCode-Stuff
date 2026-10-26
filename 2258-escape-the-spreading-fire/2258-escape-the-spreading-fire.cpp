class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    void bfs(vector<vector<int>>& grid , vector<vector<int>>& fireTime) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    fireTime[i][j] = 0;
                }
            }
        }


        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >= n || dcol >=m || grid[drow][dcol] == 2 || (fireTime[drow][dcol] != 1e9)) continue;

                fireTime[drow][dcol] = fireTime[row][col] + 1;
                q.push({drow , dcol});
            }

        }
    }

    bool check(int mid ,vector<vector<int>>& grid,  vector<vector<int>>& fireTime) {
        int n = fireTime.size();
        int m = fireTime[0].size();
        if(mid >= fireTime[0][0]) return false;
        vector<vector<int>> vis(n , vector<int> (m , 0));
        queue<tuple<int,int,int>> q;
        vis[0][0] = 1;
        q.push({0 , 0 , mid});

        while(!q.empty()) {
            auto [row , col , time] = q.front();
            q.pop();
            if(row == n-1 && col == m-1) return true;

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >= n || dcol >=m || grid[drow][dcol] == 2 || vis[drow][dcol]) continue;
                if(drow == n-1 && dcol == m-1) {
                    if(time +1 > fireTime[drow][dcol]) continue;
                } else {
                    if(time +1 >= fireTime[drow][dcol]) continue;
                }

                q.push({drow , dcol , time +1});
                vis[drow][dcol] = 1;

            }

        }
        
        return false;
        
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> fireTime(n , vector<int> (m , 1e9));
        bfs(grid , fireTime);

        int low = 0 , high = n*m;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high -low)/2;

            if(check(mid , grid , fireTime)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if(ans == n*m) return 1e9;
        return ans; 


    }
};