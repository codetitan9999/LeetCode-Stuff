class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin() , nums.end());
        for(int i = n-1 ; i >= 2 ; i--) {
            int p1 = 0 , p2 = i-1;
            while(p1 < p2) {
                if(nums[p1] + nums[p2] > nums[i]) {
                    ans += p2-p1;
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        return ans;
    }
};