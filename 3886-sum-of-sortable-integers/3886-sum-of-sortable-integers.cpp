class Solution {
public:
    int n;
    vector<int> prefMax, suffMin, prefDrop;

    bool check(int k, vector<int>& nums) {

        for (int l = 0; l < n; l += k) {
            int r = l + k - 1;

            // Number of descents inside the block
            int drops = prefDrop[r] - prefDrop[l];

            // Circular comparison: last -> first
            if (nums[r] > nums[l])
                drops++;

            // Cannot sort this block by rotation
            if (drops > 1)
                return false;

            // Previous blocks must not contain
            // values greater than later blocks
            if (prefMax[l] > suffMin[l])
                return false;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {

        n = nums.size();

        prefMax.assign(n + 1, 0);
        suffMin.assign(n + 1, INT_MAX);
        prefDrop.assign(n, 0);

        // Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] =
                max(prefMax[i], nums[i]);
        }

        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] =
                min(suffMin[i + 1], nums[i]);
        }

        // Prefix count of adjacent descents
        for (int i = 1; i < n; i++) {
            prefDrop[i] =
                prefDrop[i - 1] +
                (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        // Enumerate divisors
        for (int k = 1; k * k <= n; k++) {

            if (n % k != 0)
                continue;

            if (check(k, nums))
                ans += k;

            int other = n / k;

            if (other != k && check(other, nums))
                ans += other;
        }

        return ans;
    }
};