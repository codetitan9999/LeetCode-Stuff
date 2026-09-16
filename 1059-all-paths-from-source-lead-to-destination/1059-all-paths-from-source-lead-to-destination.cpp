class Solution {
public:
    bool f(int node , unordered_map<int, vector<int>> & adj , int dest , vector<int> & vis , vector<int> & pathvis) {
        if( (adj[node].size() == 0 ) && (dest != node)) return false;; 
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(!f(it , adj , dest , vis , pathvis)) return false;

            } else if(pathvis[it]) {
                return false;
            }
        }
        pathvis[node] = 0;
        return true;

    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n , 0) , pathvis(n , 0);
        unordered_map<int, vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        return f(source , adj , destination , vis , pathvis);
    }
};