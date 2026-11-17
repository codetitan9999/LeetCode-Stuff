class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = palin(s, i, j);
            }
        }

        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = n; i >= 2 * j; i--) {
                int best = 1000000;
                for (int m = 2 * (j - 1); m <= i - 2; m++) {
                    best = min(best, dp[m] + cost[m][i - 1]);
                }
                dp[i] = best;
            }
        }

        return dp[n];
    }

private:
    int palin(const string& s, int start, int end) {
        int n = end - start + 1;
        int minc = INT_MAX;
        for (int d = 1; d <= n / 2; d++) {
            if (n % d != 0) continue;
            int c = 0;
            int g = n / d;
            for (int i = 0; i < d && c < minc; i++) { 
                int left = i + start;
                int right = start + i + (g - 1) * d;
                while (left < right) {
                    if (s[left] != s[right]) c++;
                    left += d;
                    right -= d;
                }
            }
            minc = min(minc, c);
        }
        return minc;
    }
};