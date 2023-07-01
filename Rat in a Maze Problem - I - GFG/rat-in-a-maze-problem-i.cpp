//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fun(int row , int col , vector<vector<int>> & grid , vector<vector<int>> & vis , int n , vector<string> & ans , string path ) {
        if(row == n-1 && col == n-1) {
            ans.push_back(path);
            return;
        }
        string move="UDLR";
        int delrow[] = {-1 , +1 , 0 , 0};
        int delcol[] = {0 , 0 ,-1 , 1};
        
        for(int i = 0 ; i < 4 ; i++) {
            int drow = row+delrow[i];
            int dcol = col + delcol[i];
            if(drow>=0 && dcol >=0 && drow < n && dcol < n && vis[drow][dcol] == 0 && grid[drow][dcol] == 1) {
                
                vis[drow][dcol] =1;
                fun(drow, dcol , grid , vis , n , ans , path+move[i]);
               
                vis[drow][dcol] =0;
            }
        }
}
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<int>> vis(n , vector<int> ( n , 0));
        vector<string> ans;
        
        if(m[0][0] != 1)
        return ans;
        vis[0][0] = 1;
        fun(0 , 0 , m , vis , n , ans , "");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends