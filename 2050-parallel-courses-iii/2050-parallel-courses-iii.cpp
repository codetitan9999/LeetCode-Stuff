class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int , vector<int>> adj;
        vector<int> indegree(n , 0);
        vector<int> ans(n , 0);
        for(auto it : relations) {
            adj[it[0] -1].push_back(it[1]-1);
            indegree[it[1]-1]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
            ans[i] = time[i];
        }
 
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    ans[it] = max(ans[it] , ans[node] + time[it]);
                    indegree[it]--;
                    if(indegree[it] == 0) {
                        q.push(it);
                    }
                }
                
            }

        }
        return *max_element(ans.begin() , ans.end());
    }
};