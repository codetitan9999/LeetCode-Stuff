class Solution {
public:
    vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0  , 1 ,  0 , -1};
    const int mod = 1e9+7;
    int f(int row , int col , int move , int maxMove , int m , int n , vector<vector<vector<int>>> & dp) {
        if(move > maxMove) return 0;
        if(row < 0 || col < 0 || row >= n || col >= m) return 1;
        if(dp[row][col][move] !=-1) return dp[row][col][move]%mod;
        int cnt = 0;
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            cnt = (cnt + f(drow , dcol , move+1 , maxMove , m , n , dp)%mod)%mod;
        }
        return dp[row][col][move] = cnt%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int> (maxMove+1 , -1)));
        return f(startRow , startColumn , 0  , maxMove , n , m , dp);
    }
};