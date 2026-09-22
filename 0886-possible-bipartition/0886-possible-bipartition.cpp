class Solution {
public:
    bool dfs(int node , int col ,  unordered_map<int, vector<int>> & adj ,vector<int> & color) {
        color[node] = col;

        for(auto it : adj[node]) {
            if(color[it] == -1) {
                if(!dfs(it , 1-col , adj , color)) return false;
            } else if(color[it] == col) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1 , -1);
        bool ans = true;
        for(int i = 1; i <= n ; i++) {
            if(color[i] == -1) {
                if(!dfs(i , 0,  adj , color)) return false;
            }
        }
        return true;
        
    }
};