class Solution {
public:
    vector<int> delrow = {0 , 1 , 0 , -1};
    vector<int> delcol = {1 , 0 , -1 , 0};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();


        vector<vector<int>> dist(n , vector<int> (m , INT_MAX));
        priority_queue<vector<int>  , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0, 0 , 0, 1});
        dist[0][0] = 0;

        while(!pq.empty()) {
            int row = pq.top()[1];
            int col = pq.top()[2];
            int timer = pq.top()[0];
            int isOne = pq.top()[3];
            pq.pop();
            if(dist[row][col] != timer) continue; 

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >=n || dcol >=m) continue;
                int newTimer = max(timer , moveTime[drow][dcol]);
                int moves = (isOne ? 1: 2) + newTimer;
                if(dist[drow][dcol] > moves) {
                    dist[drow][dcol] = moves;
                    pq.push({moves , drow , dcol , !isOne});
                }

            }
            
        }
        return dist[n-1][m-1];
        
    }
};