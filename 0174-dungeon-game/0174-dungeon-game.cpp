class Solution {
public:
    int f(int row , int col , vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        if(row >= n || col >= m) return INT_MAX;
        if(row == n-1 && col == m-1) {
            if(dungeon[row][col] > 0) {
                return 1;
            } else {
                return abs(dungeon[row][col]) +1;
            }
        }
        if(dp[row][col] !=-1) return dp[row][col];
        int down = f(row+1 , col , dungeon , dp);
        int right = f(row , col+1 , dungeon, dp);
        int ans = min(down , right) - dungeon[row][col];
        if(ans > 0) return dp[row][col] = ans;
        else return dp[row][col] =  1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        // right --> row , col+1
        // down --> row+1 , col
        vector<vector<int>> dp(n , vector<int> (m , -1));
        return f(0 , 0 , dungeon , dp);

    }
};