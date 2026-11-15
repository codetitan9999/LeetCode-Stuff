class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1, odd = 0;
        long long ans = 0;
        int parity = 0;

        for (int num : arr) {
            parity = (parity + num % 2 + 2) % 2;

            if (parity == 0) {
                ans = (ans + odd) % MOD;
                even++;
            } else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
