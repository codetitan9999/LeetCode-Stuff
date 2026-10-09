class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<vector<int>> adj(n+1, vector<int> (n+1 , 0));

        for(auto it : corridors) {
            adj[it[0]][it[1]] = 1;
            adj[it[1]][it[0]] = 1;
        }


        int ans = 0;


        for(int u = 1 ; u <= n ; u++) {
            for(int v = u+1 ; v <=n ; v++) {
                for(int w = v+1 ; w <=n ; w++) {
                    if(adj[u][v] && adj[v][w] && adj[w][u]) {
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};