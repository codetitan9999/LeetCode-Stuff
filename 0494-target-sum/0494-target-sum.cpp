class Solution {
public:
    int f(int ind , vector<int>& nums, int sum , map<pair<int,int>,int> & dp) {
        if(ind == 0) {
            if(sum == 0 && nums[ind] == 0) return 2;
            if(sum == 0 || nums[ind] == sum) return 1;
            return 0;
        }
        
        if(dp.count({ind, sum})) return dp[{ind, sum}];
        int nt = f(ind-1 , nums , sum , dp);
        int t = f(ind-1 , nums , sum - nums[ind] , dp);
        return dp[{ind, sum}] = t + nt;
    }

    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if((sum + t) % 2 != 0) return 0;
        int tot = (sum+t)/2;
        map<pair<int,int>,int> dp;
        return f(n-1 ,nums , (sum+t)/2 , dp );


        
    }
};