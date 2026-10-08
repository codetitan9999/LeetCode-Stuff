class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> adj;

        vector<int> indegree(n+1 , 0);
        queue<int> q;
        for(auto it : relations) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i = 1 ; i <= n ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        if(q.size() == 0) return -1;
        int cnt = 0;
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                int node = q.front();
                cnt++;
                q.pop();
                for(auto it : adj[node]) {
                    indegree[it]--;
                    if(indegree[it] == 0) q.push(it);
                }
            }
        }
        if(cnt != n) ans = -1;

        return ans;
        
    }
};