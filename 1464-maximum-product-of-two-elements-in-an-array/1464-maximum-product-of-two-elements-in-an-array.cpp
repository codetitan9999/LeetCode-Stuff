class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin() , nums.rend());
        int n = nums.size();
        transform(nums.begin() , nums.end(), nums.begin() , [](int x) {
            return x-1;
        });
        return max(nums[0]*nums[1] , nums[n-1]*nums[n-2]);
    }
};