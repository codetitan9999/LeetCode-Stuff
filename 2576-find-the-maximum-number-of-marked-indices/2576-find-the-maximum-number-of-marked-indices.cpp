class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int i = 0 , j = n/2;
        int ans = 0;
        while(i < n/2 && j < n) {
            if(2*nums[i] <= nums[j]) {
                ans += 2;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};