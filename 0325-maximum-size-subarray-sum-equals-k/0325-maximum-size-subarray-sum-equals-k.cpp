typedef long long ll;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        ll n = nums.size() ;
        vector<ll> prefix(n, 0);
        ll ans = 0;
        if(k == nums[0]) ans = 1;
        prefix[0] = nums[0];

        for(ll i = 1 ; i < n ; i++) {
            prefix[i] = prefix[i-1] + nums[i];
            if(prefix[i] == k) {
                ans = max(ans , i+1);
            }
        }

        unordered_map<ll,ll> mp;

        for(ll i = 0 ; i < n ;i++) {
            ll sum = prefix[i] - k;
            if(mp.count(sum)) {
                ans = max(ans , i - mp[sum]);
            }
            if(!mp.count(prefix[i]))
            mp[prefix[i]] = i;
        }
        return ans;
    }
};