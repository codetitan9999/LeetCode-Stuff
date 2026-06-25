class Solution {
public:
    int f(int row , int colA , int colB , vector<vector<int>>& grid , vector<vector<vector<int>>> & dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(colA < 0 || colB < 0 || colA >= m || colB >=m) return INT_MIN;
        if(row == n-1) {
            if(colA == colB) return grid[row][colA];

            return grid[row][colA] + grid[row][colB];
        }

        if(dp[row][colA][colB] != -1) return dp[row][colA][colB];
        int ans = 0;

        for(int i = -1 ; i <= 1 ; i++) {
            for(int j = -1 ; j <= 1 ; j++) {
                ans = max(ans , f(row+1 , colA+i , colB+j , grid, dp));
            }
        }

        if(colA == colB) {
            ans += grid[row][colA];
        } else {
            ans += grid[row][colA] + grid[row][colB];
        }
        return dp[row][colA][colB] = ans;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int> (m , -1)));

        return f(0 , 0 , m-1 , grid , dp);
        
    }
};