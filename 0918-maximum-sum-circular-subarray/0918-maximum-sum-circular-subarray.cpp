class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {


        int maxSum = INT_MIN;
        int sum = 0;
        int minSum = INT_MAX;
        int tot = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
            maxSum = max(maxSum , sum);
            if(sum < 0) sum = 0;
            tot += nums[i];

        }

        for(int i = 0 ; i < nums.size() ; i++) {

            sum += nums[i];

            minSum = min(minSum , sum);
            if(sum > 0) sum = 0;

        }

        if(maxSum < 0) return *max_element(nums.begin() , nums.end());

        return max(maxSum ,  tot - minSum);
    }
};