class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<vector<long long>> C;

    long long f(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
            return 1;

        vector<int> left, right;

        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftWays = f(left);
        long long rightWays = f(right);

        int L = left.size();
        int R = right.size();

        long long ans = C[L + R][L];

        ans = (ans * leftWays) % MOD;
        ans = (ans * rightWays) % MOD;

        return ans;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        C.assign(n + 1, vector<long long>(n + 1, 0));

        // Pascal's triangle
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] =
                    (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // Subtract original ordering
        return (f(nums) - 1 + MOD) % MOD;
    }
};