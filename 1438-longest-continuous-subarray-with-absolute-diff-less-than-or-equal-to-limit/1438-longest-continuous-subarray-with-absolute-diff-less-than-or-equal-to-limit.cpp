class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD;
        deque<int> minD;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Maintain decreasing deque for maximum
            while (!maxD.empty() &&
                   nums[maxD.back()] < nums[right]) {
                maxD.pop_back();
            }

            maxD.push_back(right);

            // Maintain increasing deque for minimum
            while (!minD.empty() &&
                   nums[minD.back()] > nums[right]) {
                minD.pop_back();
            }

            minD.push_back(right);

            // Shrink invalid window
            while (nums[maxD.front()] -
                   nums[minD.front()] > limit) {

                if (maxD.front() == left) {
                    maxD.pop_front();
                }

                if (minD.front() == left) {
                    minD.pop_front();
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};