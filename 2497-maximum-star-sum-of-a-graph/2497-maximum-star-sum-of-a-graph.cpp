class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int, vector<int> , greater<int>>> adj(n);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push(vals[v]);
            adj[v].push(vals[u]);
            if(adj[u].size() > k) adj[u].pop();
            if(adj[v].size() > k) adj[v].pop();
        }

        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            auto pq = adj[i];
            int sum = vals[i];
            while(!pq.empty()) {
                if(pq.top() > 0) sum += pq.top();
                pq.pop();

            }
            ans = max(ans , sum);

        }
        return ans;


    }
};