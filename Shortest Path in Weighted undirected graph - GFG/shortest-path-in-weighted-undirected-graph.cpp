//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        vector<int> dist(n+1 , 1e9);
        vector<int> par(n+1);
        for(int i = 0 ; i < par.size() ; i++) {
            par[i] = i;
        }
        set<pair<int,int>> st;
        st.insert({0 , 1});
        dist[1] = 0;
        while(!st.empty()) {
            auto it = *st.begin();
            int node = it.second;
            int dis = it.first;
            st.erase({dis , node});
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjDist = it.second;
                if(dist[adjNode] > dist[node] + adjDist) {
                    if(dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode] , adjNode});
                    }
                    dist[adjNode] = dist[node] + adjDist;
                    st.insert({dist[adjNode] , adjNode});
                    par[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9)
        return {-1};
        vector<int> ans;
        int node = n;
        while(par[node] != node) {
            ans.push_back(node);
            node = par[node];
        }
        ans.push_back(1);
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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