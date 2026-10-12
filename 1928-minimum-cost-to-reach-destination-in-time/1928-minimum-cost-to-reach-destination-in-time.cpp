class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        unordered_map<int , vector<pair<int,int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
       
        }

        vector<vector<int>> dist(n , vector<int> (maxTime+2 ,  1e9));
        dist[0][0] = passingFees[0];

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({dist[0][0] , 0 , 0});

        while(!pq.empty()) {
            int cost = pq.top()[0];
            int t = pq.top()[1];
            int node = pq.top()[2];
            pq.pop();
            if(dist[node][t] != cost) continue;
            if(node == n-1) {
                return cost;
            }

            for(auto [adjNode , adjTime] : adj[node]) {

                if(t + adjTime > maxTime) continue;

                if(dist[adjNode][t + adjTime] > dist[node][t] + passingFees[adjNode]) {
                    dist[adjNode][t + adjTime] = dist[node][t] + passingFees[adjNode];
                    pq.push({dist[adjNode][t+adjTime] , t + adjTime , adjNode});
                }

            }
        }
        return -1;


        
    }
};