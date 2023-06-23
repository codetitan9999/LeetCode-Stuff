//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row , int col , vector<vector<int>> & vis , vector<vector<int>> & grid , vector<pair<int,int>> &ans) {
        int n = grid.size();
        int m = grid[0].size();
        int strow = row;
        int stcol = col;
        int delrow[] = {0 , 1 , 0 , -1};
        int delcol[] = {-1 , 0 , 1, 0};
        queue<pair<int,int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            ans.push_back({r-strow, c -stcol});
            for(int i = 0 ; i < 4 ; i++) {
                int drow = r + delrow[i];
                int dcol = c + delcol[i];
                if(drow >=0 && dcol >=0 && drow < n && dcol < m && vis[drow][dcol] == 0 && grid[drow][dcol] == 1) {
                    vis[drow][dcol] =1 ;
                    q.push({drow,dcol});
                }
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis( n , vector<int> (m , 0));
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = 0 ;  j < m ; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    vector<pair<int,int>> vp;
                    bfs(i, j , vis, grid , vp);
                    st.insert(vp);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends