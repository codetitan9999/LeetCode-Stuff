class Solution {
public:
    vector<int> delrow = {-1 , 0 ,1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();


        vector<vector<int>> dist(n , vector<int> (m , INT_MAX));

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        dist[0][0] = 0;
        pq.push({0 , 0 , 0});
        while(!pq.empty()) {
            int row = pq.top()[1];
            int col = pq.top()[2];
            int timer = pq.top()[0];
            pq.pop();
            if(dist[row][col] != timer) continue;
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >=n || dcol >=m) continue;
                int newTimer = max(timer , moveTime[drow][dcol]);
                int moves = newTimer +1;

                if(dist[drow][dcol] > moves) {
                    dist[drow][dcol] = moves;
                    pq.push({moves , drow , dcol});
                }
            }
        }
        return dist[n-1][m-1];
        
    }
};