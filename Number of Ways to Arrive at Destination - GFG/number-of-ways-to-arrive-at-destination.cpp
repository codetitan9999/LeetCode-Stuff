//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef long long ll;
class Solution {
  public:
    ll countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<ll,ll>> adj[n];
        for(auto it : roads) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u , wt});
        }
        ll mod = 1e9+7;
        vector<ll> dist(n , 1e18);
        vector<ll> ways(n , 0);
        ways[0] = 1;
        dist[0] = 0;
        set<pair<ll,ll>> st;
        st.insert({0 , 0});
        while(!st.empty()) {
            ll node = (*st.begin()).second;
            ll d = (*st.begin()).first;
            st.erase({d,node});
            for(auto it : adj[node]) {
                ll adjNode = it.first;
                ll adjDist = it.second;
                if(dist[adjNode] > d + adjDist) {
                    if(dist[adjNode] != 1e18) {
                        st.erase({dist[adjNode] , adjNode});
                    }
                    ways[adjNode] = ways[node];
                    dist[adjNode] = d + adjDist;
                    st.insert({dist[adjNode] , adjNode});
                    
                }
                else if(dist[adjNode] == d + adjDist) {
                    ways[adjNode]= (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends