class Solution {
public:
    int n;
    const int mod = 1e9+7;
    int f(int node , unordered_map<int, vector<pair<int,int>>> & adj , vector<long long> & dist , vector<int> & dp) {
        if(node == n) return 1;
        if(dp[node] != -1) return dp[node];
        int ans = 0;
        for(auto it : adj[node]) {
            int adjNode = it.first;
            if(dist[adjNode] >= dist[node]) continue;
            ans = (ans + f(adjNode, adj , dist , dp) )%mod;
        }
        return dp[node] = ans%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n = n;

        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        vector<long long> dist(n+1 , LLONG_MAX);
        dist[n] = 0;
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({0 , n});
        while(!pq.empty()) {
            int node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if(d != dist[node]) continue;

            for(auto it : adj[node]) {
                int adjD = it.second;
                int adjNode = it.first;

                if(dist[adjNode] > dist[node] + adjD) {
                    dist[adjNode] = dist[node] + adjD;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        vector<int> dp(n+1 , -1);

        return f(1 , adj , dist , dp);

    }
};