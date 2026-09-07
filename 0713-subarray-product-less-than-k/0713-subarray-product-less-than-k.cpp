class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0 , j = 0;
        int ans = 0;

        long long prod = 1;
        while(j < n ) {
            prod *= nums[j];

            while(prod >= k) {
                prod /= nums[i];
                i++;
                if(prod == 1) break;
            }

            if(prod < k) ans += j-i+1;

            j++;
        }

        return ans;
    }
};