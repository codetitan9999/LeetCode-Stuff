class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            string s = to_string(nums[i]);

            for (int j = 0; j < s.length(); j++) {
                sum += s[j] - '0';
            }

            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};