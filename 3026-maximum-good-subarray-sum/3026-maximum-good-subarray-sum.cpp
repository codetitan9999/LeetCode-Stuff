class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        /*
            nums[left] - nums[right] = +- k
            nums[left] = nums[right] +k or nums[right] -k

            we want sum, so consider each element as right and check if that target value for left is found 
            If found we need to subtract from the sum till that index


            we maintain a prefix array which stores nums[left]-> minimum possible sum before that left
            and the prefix sum till nums[right] ,
            The moment we find target value in map , we subtract that value taken from map from the prefix sum


            ex: 3 -10 3 4 6
        */



        unordered_map<long long , long long> mp;

        long long prefix = 0 , ans = LLONG_MIN;


        for(auto x : nums) {

            if(mp.count(x)) {
                mp[x] = min(mp[x] , prefix);
            } else {
                mp[x] = prefix;
            }

            prefix += x;

            if(mp.count(x - k)) {
                ans = max(ans , prefix - mp[x-k]);
            }

            if(mp.count(x+k)) {
                ans = max(ans , prefix - mp[x+k]);
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};