class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> ans(n , 1e9);
        unordered_map<int , vector<pair<int,int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        ans[0] = 0;
        pq.push({0 , 0});
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(ans[node] != d) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjD = it.second;
                if((d + adjD < disappear[adjNode]) && (ans[adjNode] > adjD+d)) {
                    ans[adjNode] = d + adjD ;
                    pq.push({ans[adjNode] , adjNode});
                }
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if(ans[i] == 1e9) ans[i] = -1;
        }
        return ans;

        
    }
};