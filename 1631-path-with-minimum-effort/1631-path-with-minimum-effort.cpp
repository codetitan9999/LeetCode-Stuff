class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e8));
        
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;

        dist[0][0] = 0;
        pq.push({0 , 0 , 0});

        while(!pq.empty()) {
            int row = pq.top()[1];
            int col = pq.top()[2];
            int d = pq.top()[0];
            pq.pop();
            if(row == n-1 && col == m-1) return d;

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow >= n || dcol >= m || drow <0 || dcol < 0) continue;
                int adjDist = abs(heights[row][col] - heights[drow][dcol]);
                int maxDiff = max(d , adjDist);

                if(maxDiff < dist[drow][dcol]) {
                    dist[drow][dcol] = maxDiff;
                    pq.push({maxDiff , drow , dcol}); 
                } 
            }
        }

        return 0;
        

        
    }
};