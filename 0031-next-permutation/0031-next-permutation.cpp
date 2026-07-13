class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = n-2;
        while(ind >= 0 && nums[ind] >= nums[ind+1]) ind--;
        if(ind < 0) {
            reverse(nums.begin() , nums.end());
            return;
        }
        int x = n-1;
        for(int i = n-1 ; i > ind ; i--) {
            if(nums[i] > nums[ind]) {
                x = i;
                break;
            }
        }
        
        swap(nums[ind] , nums[x]);
        reverse(nums.begin() + ind +1, nums.end());

    }
};