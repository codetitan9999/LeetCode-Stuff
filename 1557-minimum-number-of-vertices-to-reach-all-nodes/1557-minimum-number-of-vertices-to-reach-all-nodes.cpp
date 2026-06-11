class Solution {
public:
    void dfs(int node , unordered_map<int, vector<int>> & adj , vector<int> & vis , stack<int> & st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it , adj , vis, st);
            }
        }
        st.push(node);
    }
    void dfs(int node , unordered_map<int, vector<int>> & adj , vector<int> & vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it , adj , vis);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        vector<int> vis1(n , 0);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        stack<int> st;
        for(int i = 0  ; i < n ; i++) {
            if(!vis1[i]) {
                dfs(i , adj , vis1 , st);
            }
        }
        vector<int> vis2(n , 0);
        vector<int> ans;
        while(!st.empty()) {
            int i = st.top();
            st.pop();
            if(!vis2[i]) {
                ans.push_back(i);
                dfs(i , adj , vis2);
            }
        }
        return ans;
    }
};