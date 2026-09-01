class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int start = 0 , end = 0;
        int ans = 0;
        while(end < nums.size()) {

            mp[nums[end]]++;

            while(mp[nums[end]] > k) {
                mp[nums[start]]--;
                start++;
            }

            if(mp[nums[end]] <= k) ans = max(ans , end - start +1);
            end++;

        }
        return ans;
        
    }
};