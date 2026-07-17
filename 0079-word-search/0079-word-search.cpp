class Solution {
public:
    bool dfs(int row , int col , int ind , vector<vector<char>>& board , string & word , vector<vector<int>> & vis) {
        int n = board.size();
        int m = board[0].size();
        if(ind == word.size()) return true;
        vis[row][col] = 1;
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0, -1};
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow < 0 || dcol < 0 || drow >= n || dcol >=m || vis[drow][dcol]) continue;
            if( board[drow][dcol] == word[ind] ) {
                if(dfs(drow , dcol , ind+1 ,board ,  word , vis)) {
                    return true;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int ind = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(board[i][j] == word[ind]) {
                    vector<vector<int>> vis(n , vector<int> ( m , 0));
                    if(dfs(i , j , ind+1 , board , word , vis)) return true;
                }
            }
        }
        return false;
        
    }
};