class Solution {
public:
    
    int lcs(string a, string b, int n, int m) {
        if(n==0||m==0)
            return 0;
        int mat[n+1][m+1];
        for(int i=0;i<=n;i++) mat[i][0]=0;
        for(int j=0;j<=m;j++) mat[0][j]=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(a[i-1]==b[j-1])
                    mat[i][j]=1+mat[i-1][j-1];
                else 
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    }
    }
        return mat[n][m];
        
    }
    int longestPalindromeSubseq(string s) {
        if(s.length()==0)
            return 0;
        string x=s;
        reverse(x.begin(),x.end());
        return lcs(s,x,s.length(),x.length());
    }
};