class Solution {
public:
    long long mod = 1e9+7;
    int f(int dice , int k , int sum, vector<vector<int>> & dp) {
        if(sum < 0) return 0;
        if(dice == 0) return (sum ==0);
        if(dp[dice][sum] !=-1) return dp[dice][sum];
        long long ways = 0;
        for(int i = 1 ; i <= k ; i++) {
            ways = (ways +  f(dice-1 , k , sum-i, dp) % mod) % mod;
        }
        return dp[dice][sum] = ways%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1 , vector<int> (target+1 , -1));
        return f(n , k , target, dp);

        
    }
};