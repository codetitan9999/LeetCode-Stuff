class Solution {
public:
    void f(string a , string b , vector<vector<int>> & dp) {
        int n = a.length() , m = b.length();
        

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++ ) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] =  1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    }
    string shortestCommonSupersequence(string a, string b) {

        int n = a.length() , m = b.length();
        vector<vector<int>> dp(n + 1  , vector<int> (m +1 , 0));
        f(a , b , dp);
        int i = n , j = m;

        string ans = "";
        while(i > 0 && j > 0) {
            if(a[i-1] == b[j-1]) {
                ans = b[j-1] + ans;
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                ans = a[i-1] + ans;
                i--;
            } else {
                ans = b[j-1] + ans;
                j--;
            }
        }

        while(i > 0) {
            ans = a[i-1] + ans;
            i--;
        }

        while(j > 0) {
            ans = b[j-1] + ans;
            j--;
        }
        return ans;


    }
};