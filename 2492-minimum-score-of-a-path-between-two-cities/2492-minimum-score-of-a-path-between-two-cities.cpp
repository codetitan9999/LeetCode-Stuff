class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<pair<int,int>>> adj;
        vector<int> vis(n+1 , 0);
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                ans = min(ans , it.second);
                int adjNode = it.first;
                if(!vis[adjNode]) {

                    q.push(adjNode);
                    vis[adjNode] = 1;
                }
            }

        }
        return ans;
        
    }
};