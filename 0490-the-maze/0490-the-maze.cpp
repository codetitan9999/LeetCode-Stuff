class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();

        queue<vector<int>> q;
        vector<vector<int>> vis(n , vector<int> (m , 0));
        q.push(start);
        vis[start[0]][start[1]] = 1;

        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();
            if(row == destination[0] && col == destination[1]) return true;

            for(int i = 0 ; i < 4 ; i++) {
                int dr = delrow[i];
                int dc = delcol[i];
                int nrow = row;
                int ncol = col;
                while(nrow + dr >= 0 && nrow + dr < n && ncol + dc < m && ncol + dc >= 0 && maze[nrow + dr][ncol + dc] == 0) {
                    nrow = nrow + dr;
                    ncol = ncol + dc;
                }
                if(!vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
                
            }
        }
        return false;
        
    }
};