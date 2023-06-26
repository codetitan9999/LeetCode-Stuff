//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    public:
    vector<int> parent,rank , size;
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1 , 0);
        size.resize(n+1 , 1);
        for(int i = 0 ; i <=n ; i++)
        parent[i] = i;
    }
    int findUPar(int u) {
        if(parent[u] == u)
        return u;
        return parent[u] = findUPar(parent[u]);
    }
    void unionBySize(int u , int v) {
        int ult_par_u = findUPar(u);
        int ult_par_v = findUPar(v);
        if(ult_par_u ==  ult_par_v)
        return;
        if(size[ult_par_u] < size[ult_par_v]) {
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v]+=size[ult_par_u];
        }
        else {
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u]+= size[ult_par_v];
        } 
    }
    void unionByRank(int u , int v) {
        int ult_par_u = findUPar(u);
        int ult_par_v = findUPar(v);
        if(ult_par_u ==  ult_par_v)
        return;
        if(rank[ult_par_u] < rank[ult_par_v]) {
            parent[ult_par_u] = ult_par_v;
        }
        else if(rank[ult_par_u] > rank[ult_par_v]){
            parent[ult_par_v] = ult_par_u;

        }
        else {
            rank[ult_par_u]++;
            parent[ult_par_v] = ult_par_u;
        } 
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        DisjointSet ds(V);
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0 ; i < V ; i++) {
            for(auto it : adj[i]) {
                edges.push_back({it[1] , { i , it[0]}});
            }
        }
        int ans = 0 ;
        sort(edges.begin() , edges.end());
        for(auto it : edges) {
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;
            if(ds.findUPar(u) != ds.findUPar(v)) {
                ds.unionBySize(u,v);
                ans += wt; 
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends