class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
            int val = (sum) % k;
            if(val < 0) val += k;
            ans += mp[val];

            mp[val]++;
        }
        return ans;
    }
};