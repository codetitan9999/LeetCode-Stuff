class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        map<int,int> mp;
        int ans = 0;
        for(auto x : order) {
            auto lb = mp.lower_bound(x);
            int succ = 0;
            if(lb != mp.end()) {
                succ = lb->second;
            }
            int pre = 0;
            if(lb != mp.begin()) {
                pre = prev(lb)->second;
            }
            int depth = 1 + max(pre, succ);
            mp[x] = depth;
            ans = max(ans , depth);

        }
        return ans;
    }
};