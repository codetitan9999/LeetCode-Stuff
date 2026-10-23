class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1; // twos compliment of 1 is 11111111...

        for(int i = 0 ; i < nums.size() ; i++) {
            if(i != nums[i]) {
                ans = ans & nums[i];
            }
            
        }
        return ans == -1? 0: ans;
    }
};