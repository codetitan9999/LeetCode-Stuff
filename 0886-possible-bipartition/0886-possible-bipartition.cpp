class Solution {
public:
    bool dfs(int node, int c, vector<int> &color, vector<int>  adj[]) {
        color[node]=c;
        for(auto it : adj[node]) {
            if(color[it]==-1) {
                if(!dfs(it,!color[node],color,adj))
                return false;
            }
            else if(color[it]==color[node])
            return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto it : dislikes) {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++) {
            if(color[i]==-1) {
                if(!dfs(i,0,color,adj))
                return false;
            }
        }
        return true;
     
    }
};