class Solution {
public:
    int f(vector<int> a) {
        int n = a.size();

        int ans = 1;
        int cnt = 1;

        for(int i = 1 ; i < n ; i++) {
            if(a[i] > a[i-1]) {
                cnt++;
            } else {
                ans = max(ans , cnt);
                cnt = 1;
            }
        }
        ans = max(ans , cnt);

        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = f(nums);
        reverse(nums.begin() , nums.end());
        return max(ans , f(nums));
        
    }
};