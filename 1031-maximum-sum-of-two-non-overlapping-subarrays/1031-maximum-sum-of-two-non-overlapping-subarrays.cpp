class Solution {
public:
    int f(vector<int>& nums , int l , int r) {
        int n = nums.size();
        int rend = l+r-1;
        int maxLeft = 0;
        int ans = 0;
        while(rend < n) {

            int lend = rend-r;
            int rstart = lend+1;
            int lstart = lend-l+1;

            int left = nums[lend] - (lstart == 0 ? 0 : nums[lstart-1]);
            int right = nums[rend] - nums[rstart-1];

            maxLeft = max(maxLeft , left);
            ans = max(ans , maxLeft + right);


            rend++;
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1 ; i < n ; i++) pref[i] = pref[i-1] + nums[i];

        return max(f(pref , l , r) , f(pref , r , l));
    }
};