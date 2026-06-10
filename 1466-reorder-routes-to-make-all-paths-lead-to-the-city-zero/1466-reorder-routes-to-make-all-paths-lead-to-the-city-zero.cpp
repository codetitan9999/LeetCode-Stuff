class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int , vector<pair<int, int>>> adj;
        for(auto it : connections) {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0] , 0});
        }
        vector<int> vis(n , 0);
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        int ans = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int realEdge = it.second;
                if(!vis[adjNode]) {
                    ans += realEdge;
                    q.push(adjNode);
                    vis[adjNode] = 1;
                }
            }
        }
        return ans;

    }
};