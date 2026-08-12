class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0 , end = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        while(end < n) {
            mp[nums[end]]++;
            while(mp[nums[end]] > k) {
                mp[nums[start]]--;
                start++;
            }

            ans = max(ans , end - start + 1);
            end++;
        }
        return ans;
    }
};