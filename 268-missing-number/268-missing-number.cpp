class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xoro=0;
        for(int i=0;i<nums.size();i++)
            xoro^=nums[i]^(i+1);
        
        return xoro;
        
    }
};