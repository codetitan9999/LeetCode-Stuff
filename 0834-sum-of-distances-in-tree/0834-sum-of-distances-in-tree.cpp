class Solution {
public:
    int baseSum = 0;
    int N;
    vector<int> count;
    int dfs(int node, int par , unordered_map<int , vector<int>> & adj , int curr) {
        int totnodes = 1;
        baseSum += curr;
        for(auto it : adj[node]) {
            if(it == par) continue;

            totnodes += dfs(it , node , adj , curr+1);
        }
        count[node] = totnodes;
        return totnodes;
    }
    void dfs(int node , int par , unordered_map<int , vector<int>> & adj , vector<int> & ans) {
        for(auto child : adj[node]) {
            if(child == par) continue;
            ans[child] = ans[node] - count[child] + (N - count[child]);
            dfs(child , node , adj , ans);
        }

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<int> ans(n , 0);
        count.resize(n , 0);
        unordered_map<int , vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        baseSum = 0;
        dfs(0 , -1 , adj , 0);
        ans[0] = baseSum;
        dfs(0 , -1 , adj , ans);
        return ans;
        
    }
};