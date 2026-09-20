class Solution {
public:
    const long long mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n , LLONG_MAX) , count(n , 0);
        vector<pair<int,int>> adj[n];
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        dist[0] = 0; 
        count[0] = 1;

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long, long long>>> pq;

        pq.push({0 , 0});


        while(!pq.empty()) {
            long long node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if(d != dist[node]) continue;

            for(auto it : adj[node]) {
                long long adjNode = it.first;
                long long adjD = it.second;

                if(dist[adjNode] == dist[node] + adjD) {
                    count[adjNode] = (count[adjNode]%mod + count[node]%mod)%mod;
                } else if(dist[adjNode] > dist[node] + adjD) {
                    count[adjNode] = (count[node])%mod;
                    dist[adjNode] = dist[node] + adjD;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        return count[n-1]%mod;




    }
};