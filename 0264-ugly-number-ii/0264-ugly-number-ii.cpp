class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        int p = 0 , q = 0 , r = 0;
        for(int i = 1 ; i < n ; i++) {
           dp[i] = min({dp[p] * 2 , dp[q] * 3 , dp[r] * 5});
           if(dp[i] == dp[p]*2) p++;
           if(dp[i] == dp[q]*3) q++;
           if(dp[i] == dp[r]*5) r++;
        }
        return dp[n-1];
    }
};