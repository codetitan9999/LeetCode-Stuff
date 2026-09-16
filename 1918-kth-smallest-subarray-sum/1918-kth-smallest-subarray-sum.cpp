class Solution {
public:
    int atmostK(vector<int> & nums , int k) {
        int ans = 0;
        int i = 0 , j  = 0;
        int n = nums.size();

        int sum = 0;
        while(j < n) {
            sum += nums[j];
            while(sum > k) {
                sum -= nums[i];
                i++;
            }
            if(sum <= k) ans += j-i+1;
            j++;
        }
        return ans;
    }
    int kthSmallestSubarraySum(vector<int>& nums, int k) {

        int low = 0, high = accumulate(nums.begin() , nums.end() , 0);
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;

            int cnt = atmostK(nums , mid);
            if(cnt < k) {
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
        
    }
};