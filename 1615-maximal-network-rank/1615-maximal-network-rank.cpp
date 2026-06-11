class Solution {
public:
    bool direct(unordered_map<int , vector<int>> &adj , int u , int v) {
        for(auto it : adj[u]) {
            if(it == v)
            return true;
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<int>> adj;
        for(auto it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
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