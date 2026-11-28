class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int mn = INT_MAX, mx = 0;
        for (auto &x : items) {
            mn = min(mn, x[1]);
            mx = max(mx, x[0]);
        }

        vector<int> freq(mx + 1, 0);
        for (auto &x : items) freq[x[0]]++;

        vector<int> mult(mx + 1, 0);
        for (int f = 1; f <= mx; f++) {
            for (int k = f; k <= mx; k += f) {
                mult[f] += freq[k];
            }
        }

        vector<pair<int,int>> v;

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            int out = mult[factor] - 1;

            if (out > 0 && price < 2 * mn) {
                v.push_back({price - mn, out});
            }
        }

        sort(v.begin(), v.end());

        long long cost = 0;
        long long got = 0;

        for (auto &[extra, cnt] : v) {
            long long price = mn + extra;
            long long take = min<long long>(cnt, (budget - cost) / price);

            cost += take * price;
            got += take * 2;

            if (take < cnt) break;
        }

        got += (budget - cost) / mn;

        return (int)got;   
    }
};
