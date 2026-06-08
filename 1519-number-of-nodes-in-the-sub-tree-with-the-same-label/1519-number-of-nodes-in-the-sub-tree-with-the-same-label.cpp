class Solution {
public:
    vector<int> fun(int node , int parent , unordered_map<int , vector<int>> & adj, vector<int> & ans , string & labels) {
        vector<int> a(26, 0);
        a[labels[node]-'a'] = 1;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            vector<int> b = fun(it , node , adj , ans , labels);
            for(int i = 0 ; i < 26 ; i++) {
                a[i] += b[i];
            }
        }
        ans[node] = a[labels[node]-'a'];
        return a;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        unordered_map<int , vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        fun(0 , -1 , adj , ans , labels);
        return ans;
        
    }
};