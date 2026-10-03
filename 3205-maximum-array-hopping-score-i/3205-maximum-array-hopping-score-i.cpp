class Solution {
public:
    int maxScore(vector<int>& nums) {

        int ans = 0;
        int maxi = 0;
        int n = nums.size();

        for(int i =n-1 ; i>=0 ; i--) {
            ans += maxi;
            maxi = max(maxi , nums[i]);
        }
        return ans;
        
    }
}; 