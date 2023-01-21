//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer=1;
    void dfs(int node,int parent, vector<int> adj[],vector<int>& vis, vector<int> & marked,int low[],int tin[]) {
        vis[node]=1;
        int child=0;
        low[node]=tin[node]=timer;
        timer++;
        for(auto it : adj[node]) {
            if(it==parent) continue;
            if(!vis[it]) {
                dfs(it,node,adj,vis,marked,low,tin);
                low[node]=min(low[node],low[it]);
                if(low[it] >=tin[node] && parent!=-1) {
                    marked[node]=1;
                }
                child++;
            }
            else 
            {
                low[node]=min(tin[it],low[node]);
            }
        }
        
        if(parent==-1 && child>1) {
            marked[node]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> marked(V,0);
        vector<int> vis(V, 0);
        int low[V],tin[V];
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i,-1,adj,vis,marked,low,tin);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++) {
            if(marked[i]) {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends