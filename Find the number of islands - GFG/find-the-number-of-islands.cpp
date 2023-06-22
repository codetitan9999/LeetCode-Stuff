//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row , int col , vector<vector<int>> & vis ,  vector<vector<char>> & mat) {
       vis[row][col] = 1;
       int n = mat.size();
       int m = mat[0].size();
       for(int i = -1 ; i <= 1 ; i++) {
           for(int j = -1 ; j <= 1 ; j++) {
               int drow = row + i;
               int dcol = col + j;
               if(drow >= 0 && dcol >= 0 & dcol < m && drow < n && vis[drow][dcol] == 0 && mat[drow][dcol] == '1') {
                   dfs(drow , dcol , vis , mat);
               }
           }
       }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int> (m , 0));
        for(int i = 0 ; i < n ;i++) {
            for( int j = 0 ; j < m ; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(i,j,vis,grid);
                } 
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends