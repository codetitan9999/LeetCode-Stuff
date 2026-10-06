class Solution {
public:
    long long ans = 0;
    long long f(int node , int parent , int seats ,  unordered_map<int , vector<int>> & adj) {
        long long cnt = 1;
        for(auto it : adj[node]) {
            if(it == parent) continue;

            cnt += f(it , node , seats ,  adj);
        }

        if(node != 0)
        ans += (cnt + seats-1)/seats;

        return cnt;                         
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int , vector<int>> adj;
        for(auto it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        f(0 , -1 , seats , adj);

        return ans;
        
    }
};