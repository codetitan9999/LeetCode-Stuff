class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
        vector<vector<bool>> isPre(n , vector<bool> (n , false));
        unordered_map<int , vector<int>> adj;

        vector<int> indegree(n , 0);
        for(auto it : pre) {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                isPre[it][node] = true;

                for(int i = 0 ; i < n ; i++) {
                    if(isPre[node][i]) {
                        isPre[it][i] = true;
                    }
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        vector<bool> ans;
        for(auto it : que) {
            ans.push_back(isPre[it[1]][it[0]]);
        }
        return ans;
    }
};