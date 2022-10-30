class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int p1=0,p2=0;
        while(p1<nums.size() && nums[p1]<0)
            p1++;
        p2=p1;
        while(p2<nums.size() && nums[p2]==0)
            p2++;
        for(int i=p1;i<p2;i++)
            ans.push_back(0);
       p1--;
        while(p2<nums.size() && p1>=0 ) {
            if(abs(nums[p2])<abs(nums[p1])) {
                ans.push_back(nums[p2]*nums[p2]);
                p2++;
            }
             else {
                 ans.push_back(nums[p1]*nums[p1]);
                 p1--;
            }
              }
        while(p2<nums.size()) {
            ans.push_back(nums[p2]*nums[p2]);
                p2++;
        }
        while(p1>=0)
        {
            ans.push_back(nums[p1]*nums[p1]);
            p1--;
        }
        return ans;
    }
};