class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> best(n , INT_MAX);
        int ans = INT_MAX;
        int i = 0 , j= 0;
        int sum = 0;
        int bestLen = INT_MAX;
        while( j < n) {
            sum += nums[j];


            while(sum > target) {
                sum -= nums[i];
                i++;
            }


            while(sum == target) {
                int len = j-i+1;
                if(i > 0) {
                    int prev = best[i-1];
                    if(prev != INT_MAX)
                    ans = min(ans , len + prev);
                }
                bestLen = min(bestLen , len);
                sum -= nums[i];
                i++;
            }

            best[j] = bestLen;
            j++;
        }


        if(ans == INT_MAX) return -1;
        return ans;

    }
};