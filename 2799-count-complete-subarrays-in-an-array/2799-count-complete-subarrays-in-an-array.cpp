class Solution {
public:
    int f(vector<int> & nums , int k) {
        if(k <= 0) return 0;
        int ans = 0 , i = 0 , j = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            if(mp.size() <= k) ans += j-i+1;
            j++;
        }

        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(auto x : nums) {
            mp[x]++;
        }

        return f(nums , mp.size()) - f(nums , mp.size() -1 );
        
    }
};