class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        unordered_map<int, vector<int>> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (auto it : queries) {

            vector<int>& pos = mp[nums[it]];

            // No other equal element
            if (pos.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int index =
                lower_bound(pos.begin(), pos.end(), it)
                - pos.begin();

            int prev =
                pos[(index - 1 + pos.size()) % pos.size()];

            int next =
                pos[(index + 1) % pos.size()];

            int d1 = abs(it - prev);
            int d2 = abs(it - next);

            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};