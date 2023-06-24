//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node , vector<int> & vis , vector<int> & pathvis , vector<int> & check , vector<int> adj[]) {
        check[node] = 0;
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it , vis , pathvis , check , adj)) {
                    check[node] = 0;
                    return true;
                }
                
            }
            else if(pathvis[it]) {
                check[it] = 0;
                return true;
            }
        }
        pathvis[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        
        vector<int> vis(V, 0) , pathvis(V, 0), check(V, 0);
        
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i]) {
                dfs(i , vis , pathvis , check , adj);
                
            }
        }
        for(int i = 0 ; i < V ; i++) {
            if(check[i]) {
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends