class Solution {
public:
    bool direct(unordered_map<int , unordered_set<int>> &adj , int u , int v) {
        return adj[u].count(v);
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int , unordered_set<int>> adj;
        for(auto it : roads) {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                int count = adj[i].size() + adj[j].size();
                if(direct(adj , i , j)) count--;
                maxi = max(maxi , count);
            }
        }
        return maxi;
    }
};