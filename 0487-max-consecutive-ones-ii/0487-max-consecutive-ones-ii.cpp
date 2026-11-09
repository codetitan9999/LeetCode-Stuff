class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        int cnt = 0;

        int i = 0 , j = 0; 
        while(j < n) {
            if(nums[j] == 1) cnt++;


            while(((j-i+1) - cnt) > 1) {
                if(nums[i] == 1) cnt--;
                i++;
            }


            if(((j-i+1) - cnt) <= 1) ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};