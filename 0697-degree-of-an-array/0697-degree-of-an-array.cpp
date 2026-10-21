class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> pp;
        int degree = 0;
        for(auto it : nums) {
            pp[it]++;
            degree = max(degree , pp[it]);
        }

        int i = 0, j = 0;
        unordered_map<int , int> mp;
        int deg = 0;
        int ans = n;
        while(j < n) {
            mp[nums[j]]++;
            deg = max(deg , mp[nums[j]]);
            while(i <= j && deg > degree) {
                mp[nums[i]]--;
                deg = 0;
                for(auto it : mp) deg = max(deg , it.second);
                i++;
            }

            while(i <= j && deg == degree) {
                ans = min(ans , j-i+1);
                mp[nums[i]]--;
                deg = 0;
                for(auto it : mp) deg = max(deg , it.second);
                i++;
            }

            j++;
        }
        return ans;

    }
};