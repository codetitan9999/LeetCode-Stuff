class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp ) {
          if(m==0&&n==0)
            return 1;
         if(m<0 || n<0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int left=helper(m,n-1,dp);
        int right=helper(m-1,n,dp);
        return dp[m][n]= left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        
      return helper(m-1,n-1, dp);
        
    }
};