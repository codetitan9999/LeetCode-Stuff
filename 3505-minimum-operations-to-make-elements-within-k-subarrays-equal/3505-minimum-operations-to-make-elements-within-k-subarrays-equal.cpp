
class Solution {
    struct MedianWindow {
        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        void balance() {
            while (lo.size() > hi.size() + 1) {
                int v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() < hi.size()) {
                int v = *hi.begin();
                hi.erase(hi.begin());
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        }

        void add(int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            balance();
        }

        void remove(int v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                it = hi.find(v);
                hi.erase(it);
                sumHi -= v;
            }
            balance();
        }

        long long cost() {
            long long m = *lo.rbegin();

            return m * lo.size() - sumLo
                 + sumHi - m * hi.size();
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Cost of every window of size x
        vector<long long> cost(n - x + 1);
        MedianWindow window;

        for (int i = 0; i < x; i++)
            window.add(nums[i]);

        cost[0] = window.cost();

        for (int i = x; i < n; i++) {
            window.remove(nums[i - x]);
            window.add(nums[i]);

            cost[i - x + 1] = window.cost();
        }

        // Step 2: Select k non-overlapping windows
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip position i - 1
                curr[i] = curr[i - 1];

                // Take window [i - x, i - 1]
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
