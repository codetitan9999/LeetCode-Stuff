//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int c = it[2];
            adj[u].push_back({v ,c});
        }
        queue<pair<int , pair<int,int>>> pq;
        vector<int> dist(n , 1e9);
        pq.push({0 , {src , 0}});
        dist[src] = 0;
        while(!pq.empty()) {
            int stops = pq.front().first;
            int node = pq.front().second.first;
            int cost = pq.front().second.second;
            pq.pop();
            if(stops > K) {
                continue;
            }
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int c = it.second;
                if(dist[adjNode] > c + cost && stops <= K) {
                    dist[adjNode] = c + cost;
                    pq.push({stops + 1 , {adjNode , dist[adjNode]}});
                }
                
            }
        }
        if(dist[dst] == 1e9)
        return -1;
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends