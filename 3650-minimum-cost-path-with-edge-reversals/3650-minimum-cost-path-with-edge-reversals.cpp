class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , 2*it[2]});
        }

        vector<int> dist(n , 1e9);

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0 , 0});

        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(dist[node] != d) continue;
            for(auto it : adj[node]) {
                if(dist[it.first] > dist[node] + it.second) {
                    dist[it.first] = dist[node] + it.second;
                    pq.push({dist[it.first] , it.first});
                }
            }
        }

        return dist[n-1] == 1e9 ? -1 : dist[n-1];
    }
};