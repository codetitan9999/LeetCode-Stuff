class Solution {
public:
    int fun(unordered_map<int , vector<int>> & adj , int node , int par ,  vector<bool>& hasApple) {
        int time = 0;
        for(auto it : adj[node]) {
            if(it == par) continue;
            int fromChild = fun(adj , it , node , hasApple);
            if(fromChild > 0 || hasApple[it]) {
                time += 2 + fromChild;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int , vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return fun(adj , 0 , -1 ,  hasApple);
    }
};