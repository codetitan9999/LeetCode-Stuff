//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    
    public:
    vector<int> rank,size,parent;
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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int cnt=0;
        for(auto it : edge) {
            int u=it[0];
            int v=it[1];
            if(ds.getParent(u)==ds.getParent(v)) {
                cnt++;
            }
            else
            ds.UnionByRank(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i]==i)
            comp++;
        }
        if(cnt>=comp-1) {
            return comp-1;
        }
        else
        return -1;
        
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends