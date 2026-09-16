class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp;
        int i = 0 , j = 0;
        int sum = 0;
        int ans = 0;
        while( j < n) {
            while(mp.count(nums[j])) {
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }


            sum += nums[j];
            mp.insert(nums[j]);
            ans = max(ans , sum);
            j++;
        }
        return ans;

    }
};