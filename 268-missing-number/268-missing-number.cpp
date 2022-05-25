class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xoro=0;
        for(int i=0;i<nums.size();i++)
            xoro^=nums[i];
        for(int i=1;i<=nums.size();i++)
            xoro^=i;
        return xoro;
        
    }
};