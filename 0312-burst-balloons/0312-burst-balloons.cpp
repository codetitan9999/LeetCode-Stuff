class Solution {
public:
    int f(int i , int j , vector<int> & nums , vector<vector<int>> & dp) {
        if(i > j) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int maxi = 0;
        for(int k = i ; k <= j ; k++) {
            int val = nums[i-1] * nums[k] * nums[j+1] + f(i , k-1 , nums , dp) + f(k+1 , j , nums , dp);
            maxi = max(maxi , val);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int> (n , -1));
        return f(1 , n-2 , nums , dp);
        
    }
};