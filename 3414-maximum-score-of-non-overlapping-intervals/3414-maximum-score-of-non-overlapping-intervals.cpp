class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        struct Interval {
            int l, r, w, id;
        };
        
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) 
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });
        
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0LL, {}}));
        
        for (int i = 1; i <= n; ++i) {
            int l = arr[i - 1].l;
            long long w = arr[i - 1].w;
            int id = arr[i - 1].id;
            
            int low = 1, high = i - 1, prev = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid - 1].r < l) {
                    prev = mid;
                    low = mid + 1;
                } else 
                    high = mid - 1;
            }
            
            for (int k = 1; k <= 4; ++k) {
                auto skip = dp[i - 1][k];
                
                long long take_w = dp[prev][k - 1].first + w;
                vector<int> take_idx = dp[prev][k - 1].second;
                take_idx.push_back(id);
                sort(take_idx.begin(), take_idx.end());
                
                if (take_w > skip.first) 
                    dp[i][k] = {take_w, take_idx};
                else if (take_w == skip.first) {
                    if (take_idx < skip.second) 
                        dp[i][k] = {take_w, take_idx};
                    else 
                        dp[i][k] = skip;
                } else 
                    dp[i][k] = skip;
            }
        }
        
        return dp[n][4].second;
    }
};