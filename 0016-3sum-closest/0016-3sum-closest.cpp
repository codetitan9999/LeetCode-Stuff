class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans = 0;
        int diff = INT_MAX;

        for(int i = 0 ; i < n ; i++) {
            int p1 = i+1 , p2 = n-1;

            while(p1 < p2) {
                int val = nums[i] + nums[p1] + nums[p2];

                if(val == target) return val;
                if(abs(val-target) < diff) {
                    diff = abs(val-target);
                    ans = val;
                }

                if(val < target) {
                    p1++;
                } else {
                    p2--;
                }   
            }
        }
        return ans;
    }
};