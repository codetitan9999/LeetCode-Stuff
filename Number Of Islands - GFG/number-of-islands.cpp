//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int count=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        vector<int> ans;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(auto it : operators) {
            int u=it[0];
            int v=it[1];
            if(vis[u][v]!=1) {
                count++;
                vis[u][v]=1;
                for(int i=0;i<4;i++) {
                    int row=u+drow[i];
                    int col=v+dcol[i];
                    if(row>=0 && row<n && col<m && col>=0) {
                        if(vis[row][col]==1 && ds.getParent(row*m+col)!=ds.getParent(u*m+v)) {
                            ds.UnionBySize(u*m+v,row*m+col);
                            count--;
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends