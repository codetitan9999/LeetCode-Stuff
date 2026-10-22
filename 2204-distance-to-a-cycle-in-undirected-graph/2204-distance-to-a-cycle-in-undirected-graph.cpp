class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n , 0);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> vis(n , 0);
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] <= 1 && ! vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] <= 1 && !vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        vector<int> ans(n , 1e9);
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 2) {
                q.push(i);
                ans[i] = 0;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(ans[it] > ans[node] +1) {
                    ans[it] = ans[node] + 1;
                    q.push(it);
                }
            }

        }
        return ans;

        
    }
};