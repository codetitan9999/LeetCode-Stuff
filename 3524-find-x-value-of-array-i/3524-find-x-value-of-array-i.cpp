class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> newDp(k, 0);

            int rem = x % k;

            // Start a new subarray [x]
            newDp[rem]++;

            // Extend every subarray ending at previous index
            for (int r = 0; r < k; r++) {
                int newRem = (1LL * r * rem) % k;
                newDp[newRem] += dp[r];
            }

            // All these are valid subarrays
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = move(newDp);
        }

        return ans;
    }
};