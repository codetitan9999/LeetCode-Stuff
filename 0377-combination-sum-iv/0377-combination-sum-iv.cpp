class Solution {
public:
    int f(int ind , vector<int> & nums , int sum , vector<vector<int>> & dp) {
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        if(ind == nums.size()) return 0;
        if(dp[ind][sum] !=-1) return dp[ind][sum];
        int nt = f(ind+1 , nums , sum, dp);
        int t = f(0 , nums, sum-nums[ind], dp);
        return dp[ind][sum] = t + nt;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() , vector<int> (target+1 , -1));
        return f(0 , nums , target , dp);
        
    }
};