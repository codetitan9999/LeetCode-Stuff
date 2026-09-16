class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> dp(
            n,
            vector<long long>(k + 1, 0)
        );

        // One way to choose zero segments
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {

            long long prefix = 0;

            for (int i = 1; i < n; i++) {

                // Possible starting points for
                // a segment ending at i
                prefix =
                    (prefix + dp[i - 1][j - 1]) % MOD;

                // Don't end at i
                // +
                // End a segment at i
                dp[i][j] =
                    (dp[i - 1][j] + prefix) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};