//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj (n , vector<int> (n , -1));
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(adj[i][j] == -1) {
                    adj[i][j] = 1e8;
                }
                if(i == j) {
                    adj[i][j] = 0;
                }
            }
        }
        for(int k = 0 ; k < n ; k++) {
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < n ; j++) {
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }
        int ans = -1;
        int maxCount = n;
        for(int i = 0 ; i < n ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < n ; j++) {
                if(adj[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= maxCount) {
                maxCount = cnt;
                ans = i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends