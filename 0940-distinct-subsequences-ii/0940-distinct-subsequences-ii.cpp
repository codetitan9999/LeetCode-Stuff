class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> end(26, 0);

        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';

            long long newEnding =
                (total + 1) % MOD;

            // Remove old subsequences ending in c
            // and replace them with the new complete set.
            total =
                (total - end[idx] + newEnding + MOD) % MOD;

            end[idx] = newEnding;
        }

        return total;
    }
};