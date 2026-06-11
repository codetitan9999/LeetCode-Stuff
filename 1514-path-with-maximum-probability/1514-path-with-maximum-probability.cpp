class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int , vector<pair<int , double>>> adj;
        for(int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> p(n, 0.0);
        p[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()) {
            int node = pq.top().second;
            double d = pq.top().first;
            if(node == end_node) return d;
            pq.pop();
            for(auto it : adj[node]) {
                int adjNode = it.first;
                double prob = it.second;
                if(p[adjNode] < d*prob) {
                    p[adjNode] = 1.0*d*prob;
                    pq.push({1.0*d*prob, adjNode});
                }
            }
        }
        return 0.0;

    }
};