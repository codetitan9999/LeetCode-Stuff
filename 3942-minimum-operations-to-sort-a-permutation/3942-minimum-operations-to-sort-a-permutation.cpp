class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        bool inc = true;
        bool dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
                inc = false;
            }

            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
                dec = false;
            }
        }

        int ans = INT_MAX;

        if (inc) {
            int pos0 = -1;

            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    pos0 = i;
                    break;
                }
            }

            ans = min(ans, pos0);
            ans = min(ans, n - pos0 + 2);
        }

        if (dec) {
            int posMax = -1;

            for (int i = 0; i < n; i++) {
                if (nums[i] == n - 1) {
                    posMax = i;
                    break;
                }
            }

            ans = min(ans, posMax + 1);
            ans = min(ans, n - posMax + 1);
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};