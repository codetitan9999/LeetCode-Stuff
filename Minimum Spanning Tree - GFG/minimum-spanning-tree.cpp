//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    vector<int> rank,size,parent;
    public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int getParent(int u) {
        if(parent[u]==u)
            return u;
        return parent[u]=getParent(parent[u]);
    }
    void UnionByRank(int u, int v){
        int ulp_u=getParent(u);
        int ulp_v=getParent(v);
        if(ulp_u==ulp_v)
            return ;
        if(rank[ulp_u]<rank[ulp_v]) {
            parent[ulp_u]=ulp_v;
            
        }
        else if(rank[ulp_v]<rank[ulp_u]) {
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        
    }
    void UnionBySize(int u, int v) {
        int ulp_u=getParent(u);
        int ulp_v=getParent(v);
        if(ulp_u==ulp_v)
            return ;
        if(size[ulp_v]<size[ulp_u]) {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else  {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
           
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
        int ans=0;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++) {
            for(auto it : adj[i]) {
                edges.push_back({it[1],{i,it[0]}});
                
        }
        }
        sort(edges.begin(),edges.end());
        for(auto it : edges) {
            int dist=it.first;
            int u=it.second.first;
            int v=it.second.second;
           
            if(ds.getParent(u)!=ds.getParent(v)) {
                ans+=dist;
                ds.UnionByRank(u,v);
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