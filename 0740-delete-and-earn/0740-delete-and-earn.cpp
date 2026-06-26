class Solution {
public:
    int f(int ind , vector<int> & nums , vector<int> & dp) {
        if(ind >= nums.size()) return 0;
        if(dp[ind] !=-1) return dp[ind];
        int nt = f(ind+1 , nums , dp);
        int t = nums[ind] + f(ind+2 , nums , dp);
        return dp[ind] = max(t , nt);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin() , nums.end());
        vector<int> arr(maxVal+1 , 0);
        for(auto it : nums) {
            arr[it] += it;
        }
        vector<int> dp(maxVal+1 , -1);
        return f(0 , arr , dp);
    }
};