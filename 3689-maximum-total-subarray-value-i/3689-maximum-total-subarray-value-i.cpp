class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ans = 0, maxi = INT_MIN , mini = INT_MAX;
        
        for(auto it : nums) {
            maxi= max(maxi , it);
            mini = min(mini , it);
        }
        return (long long)(maxi-mini)*k;
        
    }
};