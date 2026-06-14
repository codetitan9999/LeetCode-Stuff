class Solution {
public:
    vector<int> delnum1 = {0,1};
    vector<int> delnum2 = {1,0};
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        set<pair<int, int>> vis;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({nums1[0]+ nums2[0] , 0 , 0});
        vis.insert({0, 0});
        vector<vector<int>> ans;
        while(!pq.empty() && k > 0) {
            auto it = pq.top();
            pq.pop();
            k--;
            int p1 = it[1] , p2 = it[2];
            ans.push_back({nums1[p1] , nums2[p2]});
            for(int i = 0 ; i < 2 ; i++) {
                int dnum1 = p1 + delnum1[i];
                int dnum2 = p2 + delnum2[i];
                if(dnum1 < nums1.size() && dnum2 < nums2.size() && !vis.count({dnum1 , dnum2})) {
                    pq.push({nums1[dnum1] + nums2[dnum2] , dnum1 , dnum2});
                    vis.insert({dnum1 , dnum2});
                }
            }

        }
        return ans;
        
    }
};