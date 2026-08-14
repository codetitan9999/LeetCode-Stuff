class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<long long , long long> mp;
        int n = nums.size();
        mp[nums[0]] = 1;
        for(int i = 1 ; i < n ; i++) {
            ans += i - mp[nums[i]-i];
            mp[nums[i]-i]++;
        }

        return ans;
    }
};