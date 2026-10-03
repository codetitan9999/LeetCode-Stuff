class Solution {
public:
    int n;
    long long f(int ind , bool robbed , vector<int>& nums, vector<int>& colors , vector<vector<long long>> & dp) {
        if(ind == n) return 0;
        if(dp[ind][robbed] !=-1) return dp[ind][robbed];
        long long take = INT_MIN , nottake = INT_MIN;
        nottake = max(nottake , 0 + f(ind+1 , false , nums , colors , dp));
        take = max(take , nums[ind] + f(ind+1 , true , nums , colors , dp));
        if(robbed) {
            if(colors[ind] == colors[ind-1]) {
                take = INT_MIN;
            }
        }
        return dp[ind][robbed] = max(take , nottake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        this->n = nums.size();
        vector<vector<long long>> dp(n , vector<long long> (2 , -1));
        return f(0 , false , nums , colors , dp);
        
    }
};