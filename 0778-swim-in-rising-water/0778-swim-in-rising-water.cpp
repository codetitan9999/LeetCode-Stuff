class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    bool check(vector<vector<int>> & grid , int t) {
        int n = grid.size();
        vector<vector<int>> vis(n , vector<int> (n , 0));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            if(row == n-1 && col == n-1) return true;
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow >=0 && dcol <n && drow < n && dcol >= 0 && vis[drow][dcol] == 0 && grid[drow][dcol] <= t) {
                    q.push({drow, dcol});
                    vis[drow][dcol] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0] , high = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            high = max(high , *max_element(grid[i].begin() , grid[i].end()));
        }

        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(grid , mid)) {
                ans = mid;
                high = mid -1;
            } else {
                low = mid+1;
            }
        }
        return ans;

    }
};