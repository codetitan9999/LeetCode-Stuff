class Solution {
public:
    int f(int i , int prevSwap , vector<int>& nums1, vector<int>& nums2 , vector<vector<int>>& dp) {
        int n = nums1.size();
        if(i == n) return 0;

        if(dp[i][prevSwap] != -1) return dp[i][prevSwap];

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        if(prevSwap) swap(prev1 , prev2);


        int ans = INT_MAX;
        //noswap

        if(nums1[i] > prev1 && nums2[i] > prev2) {
            ans = min(ans , f(i+1 , 0 , nums1 , nums2 , dp));
        }


        //swap

        if(nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans , 1 + f(i+1 , 1 , nums1 , nums2 , dp));
        }
        return dp[i][prevSwap] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n , vector<int> (2 , -1));

        return min(f(1 , 0 , nums1 , nums2 , dp) , 1+ f(1 , 1 , nums1 , nums2 , dp));
        
    }
};