class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long sum = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < k ; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }
        if(mp.size() == k)
        ans = max(ans , sum);

        for(int i = k ; i < nums.size() ; i++) {
            mp[nums[i-k]]--;
            sum -= nums[i-k];
            if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            mp[nums[i]]++;
            sum += nums[i];
            if(mp.size() == k) {
                ans = max( ans , sum);
            }
        }

        return ans;

        
    }
};