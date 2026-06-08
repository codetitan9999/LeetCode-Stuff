class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n , vector<int> (m , 0));
        vector<vector<int>> vis(n , vector<int> (m , 0));
        queue<vector<int>> q;
        for(int i = 0 ; i < n ; i++) {
            for( int j = 0 ; j < m ; j++) {
                if(mat[i][j] == 1) {
                    q.push({i , j , 0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            auto node = q.front();
            int row = node[0];
            int col = node[1];
            int steps = node[2];
            ans[row][col] = steps;
            q.pop();
            int delrow[] = {-1 , 0 , 1 , 0};
            int delcol[] = {0 , 1 , 0 , -1};
            for(int i = 0 ; i <4 ; i++) {
                    int drow = row + delrow[i];
                    int dcol = col + delcol[i];
                    if(drow < n && dcol < m && drow >=0 && dcol >=0 && mat[drow][dcol] == 0 && vis[drow][dcol] == 0) {
                        q.push({drow, dcol, steps +1});
                        vis[drow][dcol] = 1;
                    }
            }
        }
        return ans;
    }
};