//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        dist[source.first][source.second]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,source});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()) {
            int row=q.front().second.first;
            int col=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<4;i++) {
                int drow=row+delrow[i];
                int dcol=col+delcol[i];
                if(drow<n && dcol<m && drow>=0 && dcol>=0 && grid[drow][dcol]==1) {
                    if(1+d<dist[drow][dcol]) {
                        dist[drow][dcol]=1+d;
                        q.push({dist[drow][dcol], {drow,dcol}});
                    }
                }
            }
        }
        if(dist[destination.first][destination.second]==1e9)
        return -1;
        return dist[destination.first][destination.second];
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends