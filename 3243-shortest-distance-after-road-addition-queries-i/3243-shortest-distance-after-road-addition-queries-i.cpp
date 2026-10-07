class Solution {
public:
    int bfs(int node , unordered_map<int , vector<int>> & adj , vector<int> & dist , int n) {
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            for(auto it : adj[val]) {
                if(dist[it] > 1+ dist[val]) {
                    dist[it] = dist[val]+1;
                    q.push(it);
                } 
            }
        }
        return dist[n-1];

    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> dist(n);
        iota(dist.begin() , dist.end() , 0);
        vector<int> ans;
        unordered_map<int , vector<int>> adj;
        for(int i = 0 ; i < n-1 ; i++) {
            adj[i].push_back(i+1);
        }
        for(auto it : queries) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);

            if(dist[u] +1 < dist[v]) {
                dist[v] = dist[u] +1;
                ans.push_back(bfs(v , adj , dist , n));
            } else {
                ans.push_back(dist[n-1]);
            }

        }
        return ans;
    }
};