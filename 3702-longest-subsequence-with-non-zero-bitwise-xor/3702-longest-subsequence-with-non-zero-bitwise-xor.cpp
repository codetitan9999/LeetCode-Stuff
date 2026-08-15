class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xoro = 0;
        int non = 0;
        for(auto x : nums) {
            xoro = xoro ^ x;
            if(x) non = 1;
        }

        if(xoro == 0) return non ? n-1 : 0;
        return n;
    }
};