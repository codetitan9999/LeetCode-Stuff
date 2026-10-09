class Solution {
public:
    bool dfs(int boy , vector<int> & vis,  vector<vector<int>>& grid , vector<int> & matches) {
        int n = grid.size();
        int m = grid[0].size();
        for(int girl = 0 ; girl < m ; girl++) {
            if(grid[boy][girl] == 0 || vis[girl]) continue;
            vis[girl] = 1;

            if(matches[girl] == -1 || dfs(matches[girl] , vis , grid , matches)) {
                matches[girl] = boy;
                return true;
            }


        }
        return false;
    }
    int maximumInvitations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> matches(m , -1);


        int cnt = 0;



        for(int boy = 0 ; boy < n ; boy++) {
            vector<int> vis(m , 0);
            if(dfs(boy ,vis , grid , matches)) {
                cnt++;
            }
        }
        return cnt;
    }
};