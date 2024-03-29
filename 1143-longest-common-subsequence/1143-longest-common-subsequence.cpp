class Solution {
public:
//     int fun(string s1, string s2, int n, int m,vector<vector<int>> &dp) {
//         if(n<0||m<0)
//             return 0;
//         if(dp[n][m]!=-1)
//             return dp[n][m];

//         if(s1[n]==s2[m]) 
//             return dp[n][m]= 1+fun(s1,s2,n-1,m-1,dp);
//         else 
//             return dp[n][m]= max(fun(s1,s2,n-1,m,dp),fun(s1,s2,n,m-1,dp));
//     }
    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.length(),m=text2.length();
        vector<int> prev(m+1),cur(m+1);
        for(int i=0;i<=m;i++)
            prev[i]=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
        
        
    }
};