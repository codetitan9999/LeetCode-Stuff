class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int> dp(n+1 , 0);

        for(int i =2 ; i <=n ; i++) {
            dp[i] = (dp[i-1]+k)%i;
        }
        return dp[n]+1;
    }
};