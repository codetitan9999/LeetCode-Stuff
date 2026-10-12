class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {

        unordered_map<int , vector<pair<int,int>>> adj;
        for(auto it : highways) {
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u].push_back({v , d});
            adj[v].push_back({u , d});
        }

        // state -> cost for each node , discountsUsed
        vector<vector<int>> dist(n , vector<int> (discounts+1 , 1e9));

        //initially , we have 0 where the distance to reach is 0 and discounts used is 0

        dist[0][0] = 0;
        //we store cost , discountsUsed , node
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;


        pq.push({0 , 0 , 0});


        while(!pq.empty()) {
            int cost = pq.top()[0];
            int discountUsed = pq.top()[1];
            int node = pq.top()[2];
            pq.pop();
            if(cost != dist[node][discountUsed]) continue;
            if(node == n-1) return cost;

            for(auto [adjNode , adjCost] : adj[node]) {
                if(discountUsed < discounts) {
                    if(dist[adjNode][discountUsed+1] > dist[node][discountUsed] + adjCost/2) {
                        dist[adjNode][discountUsed+1] = dist[node][discountUsed] + adjCost/2;
                        pq.push({dist[adjNode][discountUsed+1] , discountUsed+1 , adjNode});
                    }
                }

                if(dist[adjNode][discountUsed] > dist[node][discountUsed] + adjCost) {
                    dist[adjNode][discountUsed] = dist[node][discountUsed] + adjCost;
                    pq.push({dist[adjNode][discountUsed] , discountUsed , adjNode});
                }

            }
        }
        return -1;

        
    }
};