class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int mask = 0;


        int i = 0 , j = 0;
        int ans = 0;
        int n = nums.size();
        while(j < n) {
            while( (nums[j] & mask) !=0 ) {
                mask ^= nums[i];
                i++;
            }


            if((nums[j] & mask ) ==0 ) {
                ans = max(ans , j-i+1);
            }

            mask |= nums[j];
            j++;
        }
        return ans;
        
    }
};