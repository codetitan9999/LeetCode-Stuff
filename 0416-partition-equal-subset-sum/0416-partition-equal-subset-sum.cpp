class Solution {
public:
    bool f(int ind , int sum , vector<int> & nums, vector<vector<int>> & dp) {
        if(sum == 0) return true;
        if(ind == 0) return (sum == nums[0]);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool nt = f(ind -1 , sum , nums , dp);
        bool t = false;
        if(nums[ind] <= sum)  {
            t = f(ind-1 , sum - nums[ind] , nums , dp);
        }
        return dp[ind][sum] = t | nt;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(sum & 1) return false;

        int n = nums.size();
        vector<vector<int>> dp (n , vector<int> (sum/2+1 , -1));
        return f(n-1 , sum/2 ,  nums  , dp);
    }
};