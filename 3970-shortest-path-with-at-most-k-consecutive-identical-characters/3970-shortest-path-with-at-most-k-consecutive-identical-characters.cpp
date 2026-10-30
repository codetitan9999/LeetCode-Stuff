class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
         vector<vector<pair<int,int>>> graph(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1}); 
        // cost, node, consecutive count of same label ending here

        while (!pq.empty()) {
            auto [cost, node, cnt] = pq.top();
            pq.pop();

            if (cost != dist[node][cnt]) continue;

            for (auto &[next, wt] : graph[node]) {
                int newCnt;

                if (labels[next] == labels[node]) {
                    if (cnt == k) continue;
                    newCnt = cnt + 1;
                } else {
                    newCnt = 1;
                }

                long long newCost = cost + wt;

                if (newCost < dist[next][newCnt]) {
                    dist[next][newCnt] = newCost;
                    pq.push({newCost, next, newCnt});
                }
            }
        }

        long long ans = INF;

        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};
