class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        unordered_map<int , vector<pair<int,int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        vector<vector<int>> dist(n , vector<int> (k+1 , 1e9));

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;

        dist[s][0] = 0;
        //dist , hops , node
        pq.push({0 , 0 , s});

        while(!pq.empty()) {
            int cost = pq.top()[0];
            int hops = pq.top()[1];
            int node = pq.top()[2];
            pq.pop();
            if(dist[node][hops] != cost) continue;
            if(node == d) return cost;

            for(auto [adjNode , adjCost] : adj[node]) {

                if(hops < k) {
                    if(dist[adjNode][hops+1] > dist[node][hops] + 0) {
                        pq.push({dist[node][hops] , hops+1 , adjNode});
                        dist[adjNode][hops+1] = dist[node][hops];
                    }
                }

                if(dist[adjNode][hops] > dist[node][hops] + adjCost) {
                    pq.push({dist[node][hops] + adjCost , hops , adjNode});
                    dist[adjNode][hops] = dist[node][hops]+ adjCost;
                }
            }
        }
        return -1;

        
    }
};