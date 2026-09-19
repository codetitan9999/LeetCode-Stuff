class Solution {
public:

    //     RED
    // 0 ------> 1
    // |          |
    // | BLUE     | RED
    // └--------> 1 ------> 2
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto it : redEdges) {
            adj[it[0]].push_back({it[1] , 0});
        }


        for(auto it : blueEdges) {
            adj[it[0]].push_back({it[1] , 1});
        }

        vector<vector<int>> dist(n , vector<int> (2 , 1e9));

        queue<vector<int>> q;
        dist[0][0] = 0;
        dist[0][1] = 0;
        q.push({0 , 0});
        q.push({0 , 1});


        while(!q.empty()) {
            int color = q.front()[1];
            int node = q.front()[0];
            q.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjColor = it.second;

                if(adjColor == color) continue;


                if(dist[adjNode][adjColor] > dist[node][color] + 1) {
                    dist[adjNode][adjColor] = dist[node][color] +1;
                    q.push({adjNode , adjColor});
                }
            }
        }

        vector<int> ans(n , -1);
        for(int i = 0 ; i < n ; i++) {
            int best = min(dist[i][0] , dist[i][1]);
            if(best == 1e9) ans[i] = -1;
            else ans[i] = best;
        }
        return ans;

    }
};