class Solution {
public:
    bool f(int i , int j , string a , string b, vector<vector<int>> & dp) {
        //base case
        
        if(i == 0 && j == 0) return true;

        if(j == 0) return false;

        if(i == 0) {
            for(int k = 0 ; k < j ; k++) {
                if(b[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i-1] == b[j-1] || (b[j-1] == '?')) {
            return dp[i][j] = f(i-1 , j-1 , a, b, dp);
        } else if(b[j-1] == '*') {
            return dp[i][j] = f(i , j-1 , a, b , dp) || f(i-1 , j , a , b , dp);
        } else {
            return dp[i][j] = false;
        }
    }
    bool isMatch(string a, string b) {
        int n = a.length() , m = b.length();

        vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));

        
        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = false;
        }

        for(int j = 0 ; j <= m ; j++) {
            bool val = true;
            for(int k = 0 ; k < j ; k++) {
                if(b[k] != '*') {
                    val = false;
                    break;
                }
            }
            dp[0][j] = val;
        }
        dp[0][0] = true;


        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {

                if(a[i-1] == b[j-1] || (b[j-1] == '?')) {
                    dp[i][j] = dp[i-1][j-1];
                } else if(b[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];

        
    }
};