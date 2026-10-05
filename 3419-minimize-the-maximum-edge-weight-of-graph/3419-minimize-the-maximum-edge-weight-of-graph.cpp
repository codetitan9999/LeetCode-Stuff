class Solution {
public:
    bool check(int n , unordered_map<int, vector<pair<int, int>>> & adj , int mid) {
        unordered_set<int> vis;
        vis.insert(0);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                if(!vis.count(it.first) && it.second <= mid) {
                    vis.insert(it.first);
                    q.push(it.first);
                }
            }
        }
        return vis.size() == n;

    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int low = INT_MAX , high = 0;
        for(auto it : edges) {
            low = min(low , it[2]);
            high = max(high , it[2]);
            adj[it[1]].push_back({it[0] , it[2]});
        }
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2 ;

            if(check(n , adj , mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }

        }
        return ans;
    }
};