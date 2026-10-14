
class Solution {
public:
    int dfs(int index, vector<int>& debt) {

        // Skip people whose balance is already zero.
        while (index < debt.size() && debt[index] == 0) {
            index++;
        }

        // Everyone has been settled.
        if (index == debt.size()) {
            return 0;
        }

        int ans = INT_MAX;

        // Try settling the current person with
        // every person having an opposite balance.
        for (int j = index + 1; j < debt.size(); j++) {

            if (debt[index] * debt[j] < 0) {

                // Settle debt[index] completely.
                debt[j] += debt[index];

                // Count this transaction and solve
                // the remaining problem.
                ans = min(ans, 1 + dfs(index + 1, debt));

                // Backtrack: restore the old balance.
                debt[j] -= debt[index];
            }
        }

        return ans;
    }

    int minTransfers(vector<vector<int>>& transactions) {

        unordered_map<int, int> balance;

        // Calculate each person's net balance.
        for (const auto& t : transactions) {
            int from = t[0];
            int to = t[1];
            int amount = t[2];

            balance[from] -= amount;
            balance[to] += amount;
        }

        vector<int> debt;

        // Zero balances need no settlement.
        for (const auto& p : balance) {
            if (p.second != 0) {
                debt.push_back(p.second);
            }
        }

        return dfs(0, debt);
    }
};
