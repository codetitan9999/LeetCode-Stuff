class Solution {
public:
    int fun(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind<0)
            return 0;
        if(ind==0)
            return nums[ind];
        if(dp[ind]!=-1)
            return dp[ind];
        
        int take=fun(nums,ind-2,dp)+nums[ind];
        int notake=fun(nums,ind-1,dp);
        return dp[ind]= max(take,notake);
        
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(nums.size()==1)
            return nums[0];
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0;i<nums.size();i++) if(i!=0) nums1.push_back(nums[i]);
        for(int i=0;i<nums.size();i++) if(i!=nums.size()-1) nums2.push_back(nums[i]);
        int left=fun(nums1,nums1.size()-1,dp);
        vector<int> mp(n,-1);
        int right=fun(nums2, nums2.size()-1,mp);
        return max(left,right);
        
    }
};