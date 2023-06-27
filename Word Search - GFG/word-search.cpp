//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs( int row , int col , int ind, vector<vector<char>>& board, string word , vector<vector<int>> & dp) 
    {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1 , 0 , 1 ,0};
        int delcol[] = {0 , 1 , 0 , -1};
        if(ind == word.size())
        return true;
        dp[row][col] = 1;
        for(int  i = 0  ; i < 4 ; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];
            if(drow>=0 && dcol >=0 && drow < n && dcol < m && dp[drow][dcol] != 1 && word[ind] == board[drow][dcol]) {
                if(dfs(drow , dcol , ind+1 , board , word , dp)) {
                    return true;
                }
            }
        }
        dp[row][col] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n , vector<int> (m , 0));
        int ind = 0;
        for(int i = 0 ; i < n ; i++) {
            for( int j = 0 ; j < m ; j++) {
                if( vis[i][j] == 0 && word[ind] == board[i][j]) {
                    if(dfs(i , j , ind+1 , board , word , vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends