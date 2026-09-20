class Solution {
public:
    vector<int> bfs(int start , unordered_map<int,vector<int>> & adj) {
        int n = adj.size();
        vector<int> vis(n , 0);

        queue<pair<int,int>> q;
        q.push({start , 0});
        vis[start] = 1;
        int lastNode = 0 , lastDist = 0 ;
        while(!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push({it , d+1});
                    vis[it] = 1;
                }
            }
            if(q.empty()) {
                lastNode = node;
                lastDist = d;
            }
        }
        return {lastNode , lastDist};
    }
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.size() == 0) return 0;
        unordered_map<int , vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int lastNode = bfs(0 , adj)[0];
        return bfs(lastNode , adj)[1];



        
    }
};