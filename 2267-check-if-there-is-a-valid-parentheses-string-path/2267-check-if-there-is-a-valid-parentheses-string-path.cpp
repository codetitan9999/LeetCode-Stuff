class Solution {
public:
    bool f(int row , int col , int  balance , vector<vector<char>>& grid ,  vector<vector<vector<int>>> & dp) {
        int n = grid.size() , m = grid[0].size();

        if(row >= n || col >= m) return false;

       

        if(grid[row][col] == '(') balance += 1;
        if(grid[row][col] == ')') balance -= 1;

        if(balance < 0) return false;

       

        if(row == n-1 && col == m-1) {
            return (balance == 0);
        }

        if(dp[row][col][balance] != -1) return dp[row][col][balance];

      


        bool right = f(row  , col+1 ,  balance , grid , dp);

        bool down = f(row+1 , col , balance , grid , dp);


        return dp[row][col][balance] = right || down ;




    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        if(grid[0][0] == ')') return 0;
        if(grid[n-1][m-1] == '(') return 0;

        vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int> (n+m+1 , -1)));

        return f(0 , 0 ,0 , grid , dp);
    }
};