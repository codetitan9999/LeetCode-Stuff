class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n , vector<int> (m , 0));
        queue<vector<int>> q;
        q.push(entrance);
        vis[entrance[0]][entrance[1]] = 1;
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto arr = q.front();
                int row = arr[0];
                int col = arr[1];
                q.pop();
                if(( arr != entrance) && (row ==0 || col == 0 || row == n-1 || col == m-1)) {
                    return level;
                }
                for(int i = 0 ; i < 4 ; i++) {
                    int drow = row + delrow[i];
                    int dcol = col + delcol[i];
                    if(drow >=0 && drow < n && dcol >=0 && dcol < m && maze[drow][dcol] != '+' && !vis[drow][dcol] ) {
                        vis[drow][dcol] = 1;
                        q.push({drow , dcol});
                    }
                } 
            }
            level++;

        }
        return -1;
    }
};