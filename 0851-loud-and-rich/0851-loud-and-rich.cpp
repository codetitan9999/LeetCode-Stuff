class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int , vector<int>> adj;
        vector<int> indegree(n , 0);
        for(auto it : richer) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<int> ans(n );
        for(int i = 0 ; i < n ; i++) ans[i] = i;

        queue<int> q;

        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) {
                q.push(i);

            }
        }


        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(quiet[ans[it]] > quiet[ans[node]]) {
                    ans[it] = ans[node]; 
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }

        }
        return ans;
       
    }
};