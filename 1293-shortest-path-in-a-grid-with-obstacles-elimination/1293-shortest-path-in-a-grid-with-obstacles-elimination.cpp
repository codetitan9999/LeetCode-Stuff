class Solution {
public:
    vector<int> delrow = {1 , 0 , -1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dist(n , vector<vector<int>> (m , vector<int> (k+1 , 1e9)));
        queue<vector<int>> pq;
        pq.push({0 , 0 ,  0 , 0 });
        dist[0][0][0] = 0;

        while(!pq.empty()) {
            int steps = pq.front()[0];
            int removed = pq.front()[1];
            int row = pq.front()[2];
            int col = pq.front()[3];
            pq.pop();
        
            if(steps != dist[row][col][removed]) continue;
            if(row == n-1 && col == m-1) return steps;

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];

                if(drow < 0 || dcol < 0 || drow >= n || dcol >= m ) continue;

                if(grid[drow][dcol] == 1 && removed < k) {
                    if(dist[drow][dcol][removed+1] > dist[row][col][removed] + 1) {
                        dist[drow][dcol][removed+1] = steps+1;
                        pq.push({steps+1 , removed+1 , drow , dcol});
                    }
                }

                if(grid[drow][dcol] == 0) {
                    if(dist[drow][dcol][removed] > dist[row][col][removed] +1) {
                        dist[drow][dcol][removed] = steps+1;
                        pq.push({steps+1 , removed , drow , dcol});
                    }
                }

            }
        }
        return -1; 
    }
};