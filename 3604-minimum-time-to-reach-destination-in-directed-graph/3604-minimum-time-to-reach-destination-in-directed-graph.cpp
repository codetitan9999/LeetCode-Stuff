class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , it[2] , it[3]});
        }


        vector<int> dist(n , 1e9);

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0 , 0});


        while(!pq.empty()) {
            int timer = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist[node] != timer) continue;

            for(auto it : adj[node]) {
                if(timer > it[2]) continue;
                int newTimer = max(timer , it[1]);
                if(dist[it[0]] > newTimer + 1) {
                    dist[it[0]] = newTimer + 1;
                    pq.push({dist[it[0]] , it[0]});
                }
            }
        }
        return dist[n-1] == 1e9 ? -1: dist[n-1];
        
        
    }
};