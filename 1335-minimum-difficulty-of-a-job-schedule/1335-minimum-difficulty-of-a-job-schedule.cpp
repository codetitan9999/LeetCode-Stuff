class Solution {
public:
    int f(int ind , int d , int n ,  vector<int>& arr , vector<vector<int>> & dp) {
        if(d == 1) {
            int maxi = arr[ind];
            for(int i = ind ; i < n ; i++) {
                maxi = max(maxi , arr[i]);
            }
            return maxi;
        }
        if(dp[ind][d] !=-1) return dp[ind][d];
        int ans = INT_MAX;
        int maxi = arr[ind];
        for(int i = ind ; i <= n-d ; i++) {
            maxi = max(maxi , arr[i]);
            ans = min(ans , maxi + f(i+1 , d-1 , n , arr , dp));
        }
        return dp[ind][d] = ans;

    }
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n , vector<int> (d+1 , -1));
        return f(0 , d, n , arr, dp);
    }
};