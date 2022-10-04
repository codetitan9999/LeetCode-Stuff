class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pf(nums.size(),1);
        // vector<int> sf(nums.size(),1);
        for(int i=1;i<nums.size();i++) {
            pf[i]=pf[i-1]*nums[i-1];
        }
        int sf=1;
        for(int i=nums.size()-1;i>=0;i--) {
            pf[i]=pf[i]*sf;
            sf*=nums[i];
        }
        return pf;
    }
};