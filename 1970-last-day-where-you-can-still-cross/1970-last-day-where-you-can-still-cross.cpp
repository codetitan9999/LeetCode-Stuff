class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    bool bfs(vector<vector<int>> & grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int> (m , 0));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < m ; i++) {
            if(grid[0][i] == 0) {
                q.push({0 , i});
                vis[0][i] = 1;
            }
        }

        while(!q.empty()) {
            auto [row , col] = q.front();
            q.pop();
            if(row == n-1) return true;
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >= n || dcol >= m || vis[drow][dcol] || grid[drow][dcol] == 1) continue;
                q.push({drow , dcol});
                vis[drow][dcol] = 1;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int m = cells.size();
        int low = 0 , high = m;
  
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<int>> grid(row , vector<int> (col , 0));
            for(int i = 0 ; i < mid ; i++) {
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }

            if(bfs(grid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
            
        }
        return ans;
        
    }
};