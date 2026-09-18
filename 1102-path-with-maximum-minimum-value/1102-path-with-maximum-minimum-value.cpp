class Solution {
public:
    vector<int> delrow = {0 , 0 , 1 , -1};
    vector<int> delcol = {1 , -1 , 0 , 0};
    int maximumMinimumPath(vector<vector<int>>& grid) {
        priority_queue<vector<int>> pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n , vector<int>(m , -1e9));


        pq.push({grid[0][0] , 0 , 0});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            int val = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            if(row == n-1 && col == m-1) return val;
            pq.pop();

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || drow >= n || dcol <0 || dcol >=m ) continue;
                if(dist[drow][dcol] < min(dist[row][col] , grid[drow][dcol])) {
                    dist[drow][dcol] = min(dist[row][col] , grid[drow][dcol]);
                    pq.push({dist[drow][dcol] , drow , dcol});
                }               
            }
        }
        return -1;
        
    }
};