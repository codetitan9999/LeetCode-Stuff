class Solution {
public:
    int f(int ind , vector<int> & arr , int sum , vector<vector<int>> & dp) {
        if(sum == 0) return 0;
        if(ind == 0) {
            if((sum % arr[ind]) == 0) return sum/arr[ind];
            else return 1e8;
        }
        if(dp[ind][sum] !=-1) return dp[ind][sum];
        int nt = f(ind-1 , arr , sum , dp);
        int t = 1e8;
        if(sum >= arr[ind]) {
            t = 1 + f(ind , arr , sum -arr[ind] , dp);
        }
        return dp[ind][sum] = min(nt , t);

    }
    int numSquares(int n) {
        vector<int> ps;
        for(int i = 1 ; i*i <= n ; i++) {
            ps.push_back(i*i);
        }
        vector<vector<int>> dp(ps.size() , vector<int> (n+1 , -1));
        return f(ps.size() -1 , ps , n , dp); 
    }
};