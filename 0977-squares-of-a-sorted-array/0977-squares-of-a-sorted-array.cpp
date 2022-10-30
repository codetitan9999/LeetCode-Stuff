class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int p1=0,p2=nums.size()-1;
        for(int i=nums.size()-1;i>=0; i--) {
            if(abs(nums[p1])> abs(nums[p2])) {
                ans[i]=nums[p1]*nums[p1];
                p1++;
            }
            else
            {
                ans[i]=nums[p2]*nums[p2];
                p2--;
            }
        }
        return ans;
    }
};