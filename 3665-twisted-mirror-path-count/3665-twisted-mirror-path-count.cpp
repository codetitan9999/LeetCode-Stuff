class Solution {
public:
    const int mod = 1e9 + 7;
    int n , m;
    int f(int row , int col , int dir,  vector<vector<int>>& grid , vector<vector<vector<int>>> &dp) {
        if(row == n-1 && col == m-1) return 1;
        if(row < 0 || col < 0 || row >= n || col >= m) return 0;
        if(dp[row][col][dir] != -1) return dp[row][col][dir];
        int right = 0 , down = 0;
        if(grid[row][col] == 1) {
            if(dir == 1) {
                return f(row + 1 , col , 0, grid ,dp)%mod;
            } else {
                return f(row , col+1 , 1 , grid , dp)%mod;
            }
        } else {
            right += f(row, col +1 , 1 , grid , dp)%mod;
            down += f(row+1 , col  , 0 , grid , dp)%mod;
        }
        return dp[row][col][dir] = (right + down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int> (3 , -1)));
        return f(0 , 0 , 2,  grid , dp)%mod;
        
    }
};