class Solution {
public:
    void dfs(int node , vector<int> & vis , vector<int> & dfsvis , unordered_map<int , vector<int>> & adj , int len , int & maxLen) {
        vis[node] =1;
        dfsvis[node] = len;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it , vis , dfsvis , adj , len+1 , maxLen);
            } else if(dfsvis[it] != 0) {
                int start = dfsvis[it];
                int curlen = dfsvis[node];
                maxLen = max(maxLen , curlen - start +1);
            }
        }
        dfsvis[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        unordered_map<int , vector<int>> adj;
        for(int i = 0 ; i < n ; i++) {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> vis(n , 0);
        vector<int> dfsvis(n , 0);
        int ans = -1;
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                dfs(i , vis , dfsvis , adj, 1 , ans);
            }
        }
        return ans;
        
    }
};