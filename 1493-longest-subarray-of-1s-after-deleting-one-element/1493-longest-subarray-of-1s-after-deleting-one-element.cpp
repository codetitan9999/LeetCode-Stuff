class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        int i = 0 , j = 0;
        int n = nums.size();

        while(j < n) {
            if(nums[j]) cnt++;

            while((j-i+1)-cnt > 1) {
                if(nums[i] == 1) {
                    cnt--;
                }
                i++;
            }

            if(((j-i+1)-cnt) <= 1) {
                ans = max(ans , cnt);
            }

            j++;
        }
        if(cnt == n) return n-1;
        return ans;   
    } 
};