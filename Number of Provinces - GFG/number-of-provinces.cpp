//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node , vector<int> & vis , vector<int> adj[] ) {
      vis[node] =1;
      for(auto it : adj[node]) {
          if(!vis[it]) {
              dfs(it, vis, adj );
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt =0;
        vector<int> vis(V+1 , 0);
        vector<int> adjs[V+1];
        
        for(int i = 0 ; i < adj.size() ; i++) {
            for(int j = 0 ; j < adj[i].size() ; j++) {
                if(adj[i][j] == 1) {
                    adjs[i+1].push_back(j+1);
                }
            }
        }
        
        for(int i = 1 ; i <= V ; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, vis , adjs);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends