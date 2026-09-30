class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int totEven = 0 , totOdd = 0;
        for(int i = 0 ; i < n ; i++) {
            if(i&1) {
                totOdd += nums[i];
            } else {
                totEven += nums[i];
            }

        }

        int even = 0 , odd = 0;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            int currEven = even + totOdd - odd  - ((i&1) ? nums[i] : 0);
            int currOdd = odd + totEven - even - ((i&1) ? 0 : nums[i]);
            if(currEven == currOdd) cnt++;

            if(i&1) {
                odd += nums[i];
            } else {
                even += nums[i];
            }
        }
        return cnt;
        
    }
};