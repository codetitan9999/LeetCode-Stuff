class Solution {
public:
    long long dijktras(int start , int k , int n , unordered_map<int , vector<pair<int,int>>> adj , vector<int>& apple) {
        long long ans = INT_MAX;
        vector<long long> dist(n+1 , 1e9);
        priority_queue<pair<long long,int> , vector<pair<long long, int>> , greater<pair<long long,int>>> pq;
        dist[start] = 0;
        pq.push({0 , start});

        while(!pq.empty()) {
            int node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if(d != dist[node]) continue;

            for(auto [adjNode , adjD] : adj[node]) {
                if(dist[adjNode] > dist[node] + (k+1) * adjD) {
                    dist[adjNode] = dist[node] + (k+1) * adjD;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            ans = min(ans , dist[i] + apple[i-1]);
        }
        return ans;
    }
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        unordered_map<int , vector<pair<int,int>>> adj;

        for(auto it : roads) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        vector<long long> ans;

        for(int i = 1 ; i <= n ; i++) {
            ans.push_back(dijktras(i , k , n , adj, appleCost));
        }
        return ans;
        
    }
};