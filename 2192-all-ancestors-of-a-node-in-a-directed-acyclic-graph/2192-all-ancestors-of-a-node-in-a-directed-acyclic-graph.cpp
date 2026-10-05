class Solution {
public:
    vector<int> f(int node , unordered_map<int, vector<int>> & adj) {
        queue<int> q;
        unordered_set<int> vis;

        q.push(node);
        vis.insert(node);
        vector<int> ans;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                if(!vis.count(it)) {
                    q.push(it);
                    vis.insert(it);
                    ans.push_back(it);
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto it : edges) {
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; i++) {
            ans.push_back(f(i , adj));
        }
        return ans;
        
    }
};