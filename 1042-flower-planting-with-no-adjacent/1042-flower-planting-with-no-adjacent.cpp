class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n , 0);

        unordered_map<int , vector<int>> adj;

        for(auto it : paths) {
            adj[it[0]-1].push_back(it[1] -1);
            adj[it[1]-1].push_back(it[0] -1);
        }
        
        for(int i = 0 ; i < n ; i++) {
            vector<int> used(5 , 0);
            for(auto it : adj[i]) {
                used[ans[it]] = 1;
            }

            for(int k = 1 ; k <= 4 ; k++) {
                if(!used[k]) {
                    ans[i] = k;
                    break;
                }
            }


        }
        return ans;
    }
};