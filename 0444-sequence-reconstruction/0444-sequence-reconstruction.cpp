class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int , vector<int>> adj;
        int n = nums.size();
        vector<int> indegree(n+1 , 0);
        for(auto it : sequences) {
            for(int i =1 ; i < it.size() ; i++) {
                int u = it[i-1];
                int v = it[i];
                adj[u].push_back(v);
                indegree[v]++;
            }
        }



        queue<int> q;
        int index = 0;

        for(int i = 1 ; i <= n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }



        while(!q.empty()) {
            if(q.size() != 1) return false;
            int node = q.front();
            q.pop();
            if(index >= n || nums[index] != node) return false;
            index++;

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return index == n;
    }
};