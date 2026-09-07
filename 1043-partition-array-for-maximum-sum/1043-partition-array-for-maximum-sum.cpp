class Solution {
public:
    int f(int ind , vector<int>& arr, int k, vector<int> & dp) {
        int n = arr.size();
        if(ind >= n) return 0;
        int maxi = arr[ind];
        int ans = 0;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind ; i < min(n , ind + k) ; i++) {
            maxi = max(maxi , arr[i]);
            int len = i - ind +1;
            ans = max(ans , maxi*len + f(i+1 , arr , k , dp));
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n , -1);
        return f(0 , arr , k , dp);
    }
};