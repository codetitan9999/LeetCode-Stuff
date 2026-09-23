class Solution {
public:
    void dijkstra(vector<int> adj[], int snode, vector<int> & dist) {
        queue<pair<int,int>> q;
        q.push({snode , 0});
        dist[snode] = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int s = q.front().second;
            q.pop();
            if(dist[node] != s) continue;
            for(auto it : adj[node]) {
                if(dist[it] > dist[node] +1) {
                    dist[it] = dist[node]+1;
                    q.push({it , dist[it]});
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++) {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> dist1(n,1e9),dist2(n,1e9);
        dijkstra(adj,node1,dist1);
        dijkstra(adj,node2,dist2);

        long long mini = 1e9 , index = -1;

        for(int i = 0 ; i < n ; i++) {
            if(max(dist1[i], dist2[i]) < mini) {
                mini = max(dist1[i], dist2[i]) ;
                index = i;
            }
        }
        return index;

    }
};