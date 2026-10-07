class Solution {
public:
    vector<int> topo(vector<int> & indegree ,  unordered_map<int , vector<int>> &adj) {
        vector<int> ans;
        int n = indegree.size();

        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
            
        }
        return ans;

    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n , 0);
        unordered_map<int , vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        int ans = -1;

        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) {
                if(ans != -1) return -1;
                ans = i;
            }
        }
        return ans;
        stack<int> st;
        unordered_set<int> vis;



        




    }
};