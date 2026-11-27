class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 0);
        for (int i = 0; i < n; i++) {
            int fi = items[i][0];
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % fi == 0) {
                    bonus[i]++;
                }
            }
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int firstValue = 1 + bonus[i];

            vector<int> take(budget + 1, NEG);

            // Buy first copy of item i
            for (int b = price; b <= budget; b++) {
                if (dp[b - price] != NEG) {
                    take[b] = dp[b - price] + firstValue;
                }
            }

            // Buy extra copies of item i
            for (int b = price; b <= budget; b++) {
                if (take[b - price] != NEG) {
                    take[b] = max(take[b], take[b - price] + 1);
                }
            }

            // Either skip item i, or buy >= 1 copies
            for (int b = 0; b <= budget; b++) {
                dp[b] = max(dp[b], take[b]);
            }
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};
