class Solution {
public:
    vector<int> topo(vector<int> adj[], vector<int> & indegree , int k ) {
        vector<int> ans(k+1 , -1);
        queue<int> q;
        for(int i = 1 ; i < indegree.size() ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int ind = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();
                ans[node] = ind++;
                q.pop();
                for(auto it : adj[node]) {
                    indegree[it]--;
                    if(indegree[it] == 0) {
                        q.push(it);
                    }
                }

            }

        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> adjRow[k+1] , adjCol[k+1];
        vector<int> inRow(k+1, 0) , inCol(k+1 , 0);
        for(auto &it : rowConditions) {
            adjRow[it[0]].push_back(it[1]);
            inRow[it[1]]++;
        }
        for(auto &it : colConditions) {
            adjCol[it[0]].push_back(it[1]);
            inCol[it[1]]++;
        }
        vector<int> row , col;
        row = topo(adjRow , inRow , k);
        col = topo(adjCol , inCol , k);

        vector<vector<int>> ans (k, vector<int> (k , 0));

        for(int i = 1 ; i <= k ; i++) {
            if(row[i] == -1 || col[i] == -1) return {};
            ans[row[i]][col[i]] = i; 
        }
        return ans;


        
    }
};