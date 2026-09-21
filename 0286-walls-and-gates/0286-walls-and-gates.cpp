class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        queue<vector<int>> q;
        int n = rooms.size() , m = rooms[0].size();

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j });
                }
            }
        }
        vector<int> delrow = {-1 , 0 , 1 , 0};
        vector<int> delcol = {0 , 1 , 0 , -1};

        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();

            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >=n || dcol >= m || rooms[drow][dcol] != INT_MAX) continue;

                rooms[drow][dcol] = rooms[row][col] +1;
                q.push({drow, dcol});
            }
        }

        
    }
}; 