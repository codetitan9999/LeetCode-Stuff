class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> vis(n , 0);
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        for(int i = 0 ; i < n ; i++) {
            pq.push({nums[i] , i});
        }
        while(!pq.empty()) {
            int val = pq.top()[0];
            int idx = pq.top()[1];
            pq.pop();
            if(vis[idx]) continue;
            ans += 1LL*val;
            vis[idx] = 1;
            if(idx-1 >= 0) vis[idx-1] = 1;
            if(idx+1 < n ) vis[idx+1] = 1;
        }
        return ans;
        
        
    }
};