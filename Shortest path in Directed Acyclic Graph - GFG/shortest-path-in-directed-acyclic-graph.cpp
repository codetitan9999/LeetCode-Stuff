//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node , stack<int> & st , vector<int> & vis , vector<pair<int,int>> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                dfs(it.first , st , vis , adj);
            }
        }
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       // code here
        vector<pair<int,int>> adj[N];
        stack<int> st;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> vis(N , 0);
        for(int i = 0 ; i < N ; i++) {
            if(!vis[i]) {
                dfs(i , st , vis , adj);
            }
        }

        vector<int> ans(N, 1e9);
        ans[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(auto it : adj[node]) {
                int child = it.first;
                int d = it.second;
                if(d+ ans[node] < ans[child]) {
                    ans[child] = d + ans[node];
                }
            }
        }
        for(int i = 0 ;i < N ; i++) {
            if(ans[i] == 1e9) {
                ans[i] = -1;
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends