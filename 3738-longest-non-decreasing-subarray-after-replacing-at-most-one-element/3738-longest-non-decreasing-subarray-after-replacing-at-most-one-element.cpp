class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        vector<int> left(n , 0);
        vector<int> right(n , 0);
        int ans = 1;
        left[0] = 1;
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] >= nums[i-1]) {
                left[i] = 1 + left[i-1];
            } else {
                left[i] = 1;
            }
            ans = max(ans , left[i]);
        }

        right[n-1] = 1;
        for(int i = n-2 ; i>=0 ; i--) {
            if(nums[i] <= nums[i+1]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 1;
            }
            ans = max(ans , right[i]);
        }


        for(int i = 0; i < n ; i++) {
            //for left
            if(i != 0)
            ans = max( ans , left[i-1] +1);


            //for right
            if(i != n-1)
            ans = max( ans , right[i+1] +1);


            //merge
            
            if(i!=0 && i != n-1 &&nums[i-1] <= nums[i+1]) {
                ans = max( ans , left[i-1] + 1 + right[i+1]);
            }
        }

        return ans;
        




    }
};