class Solution {
public:
    // because its a tree , we dont need to have a visited array , we  can simply have parent
    int cnt = 0;
    void reversals(int node , int parent , unordered_map<int , vector<pair<int,int>>> &adj ) {
        

        for(auto it : adj[node]) {
            if(it.first == parent) continue;
            int cost = it.second;
            cnt += cost;
            reversals(it.first , node , adj);

        }
    }

    void dfs(int node , int parent , unordered_map<int , vector<pair<int,int>>> &adj , vector<int> & ans) {

        for(auto it : adj[node]) {
            if(it.first == parent) continue;

            if(it.second == 1) {
                ans[it.first] = ans[node] -1;

            } else {
                ans[it.first] = ans[node] + 1;
            }
            dfs(it.first , node , adj , ans);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<pair<int,int>>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1] , 0});
            adj[it[1]].push_back({it[0] , 1});
        }

        //lets consider 0 as root first and calculate the value for it
        vector<int> ans(n , 0);

        reversals(0 , -1 , adj);

        ans[0] = cnt;
        dfs(0 , -1 , adj , ans);
        return ans;



    }
};