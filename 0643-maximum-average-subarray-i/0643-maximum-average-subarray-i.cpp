class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = -DBL_MAX;
        double sum = 0.0;
        for(int i = 0 ; i < k ; i++) {
            sum += nums[i];
        }
        ans = max(ans , (double)sum/k);

        for(int i = k ; i < n ; i++) {
            sum += nums[i];
            sum -= nums[i-k];
            ans = max(ans , sum/k);
        }
        return ans;

    }
};