class Solution {
public:
    bool check = false;
    void susdfs(int node , vector<int> & vis , vector<int> & sus , unordered_map<int , vector<int>> & adj) {
        vis[node] = 1;
        sus[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                susdfs(it , vis , sus, adj);
            }
        }
    }
    bool dfs(int node , vector<int> & vis , vector<int> & sus , unordered_map<int , vector<int>> & adj) {
        vis[node] = 1;
        if(sus[node] == 1) return true;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it , vis , sus , adj)) return true;
            }
        }
        return false;

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        bool check = false;
       vector<int> ans;
       vector<int> vis(n , 0);
       vector<int> sus(n , 0);
       unordered_map<int , vector<int>> adj;

       for(auto it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

       susdfs(k , vis , sus , adj);

        vector<int> vis2(n , 0);

        for(int i = 0 ; i < n ; i++) {
            if(!sus[i] && !vis2[i]) {
                if(dfs(i , vis2 , sus , adj)) {
                    check = true;
                    break;
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(check || !sus[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};