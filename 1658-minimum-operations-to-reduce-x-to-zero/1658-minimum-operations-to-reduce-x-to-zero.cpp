class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int,int> mp;

        int pref = 0;
        int ans = INT_MAX;
        for(int i = 0 ; i < n ;i++) {
            pref += nums[i];
            mp[pref] = i;
            if(pref == x) {
                ans = min(ans , i+1);
            }
        }
        int suf = 0;
        for(int i = n-1 ; i>=0 ;i--) {
            suf += nums[i];
            if(suf == x) {
                ans = min(ans , n-i);
            }

            if(mp.count(x-suf) && mp[x-suf] < i) {
                ans = min(ans , n-i + mp[x-suf] +1);
            }

        }
        return ans==INT_MAX?-1:ans;


        
        
    }
};