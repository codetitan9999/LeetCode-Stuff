class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";

        for (int length = 2; length <= 9; ++length) {
            for (int start = 0; start + length <= 9; ++start) {
                int num = stoi(digits.substr(start, length));

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};