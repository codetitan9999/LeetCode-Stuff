class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin() , nums.end());
        int cnt = 0;
        for(auto x : nums) {
            cnt += maxi - x;
        }
        return cnt;
    }
};