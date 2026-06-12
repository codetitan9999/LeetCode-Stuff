class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 0 || graph.size() == 1) return 0;
        unordered_map<int , vector<int>> adj;
        int n = graph.size();
        for(int i = 0 ; i < n ; i++) {
            for(auto it : graph[i]) {
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }

        /*

        Bitmasking is used because:
            ->There is an edge say 0 - 1
            ->Now I can go from 0-1 once and again in the same iter 1-0 , but moving twice is not allowed, so we need to keep track of such state.
            ->Moving from 0->1 is (1 , 0011) and 1->0 is (0 , 0011), so we can clearly establish the state difference
        */

        set<pair<int, int>> vis;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++) {
            q.push({i , (1<<i)});
        }

        int path = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();
                if(mask == ((1<<n) -1)) {
                    return path;
                }
                for(auto it : adj[node]) {
                    int newmask = (mask | (1<<it));
                    if(!vis.count({it , newmask})) {
                        q.push({it, newmask});
                        vis.insert({it, newmask});
                    }

                }
            }
            path++;
        }
        return path;
    }
};