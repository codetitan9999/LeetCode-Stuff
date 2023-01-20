//{ Driver Code Starts
// Initial Template for C++

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
    void dfs(int row,int col , vector<vector<int>> & vis, vector<vector<int>> & grid, DisjointSet & ds) {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
         for(int k=0;k<4;k++) {
            int r=row+dr[k];
            int c=col+dc[k];
            if(r>=0 && c>=0 && r<n && c<m &&grid[r][c]==1 && vis[r][c]!=1) {
                    ds.UnionBySize(row*m+col, r*m+c); 
                    dfs(r,c,vis,grid,ds);
                }
            }
            
        }
        

    int MaxConnection(vector<vector<int>>& grid) {
        // code here
      
        int n=grid.size();
        
        int m=grid[0].size();
        
        DisjointSet ds(n*m);
        
        int dr[]={-1,0,1,0};
        
        int dc[]={0,1,0,-1};
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==0 && grid[i][j]==1) {
                    dfs(i,j,vis,grid,ds);
                }
            }
        }
        int ans=1;
        
   
        
        for(int i=0;i<n;i++) {
            
            for(int j=0;j<m;j++) {
                
                if(grid[i][j]==0) {
                    
                    int count=0;
                    
                    unordered_set<int> sety;
                    
                    for(int k=0;k<4;k++) {
                        
                        int r=i+dr[k];
                        
                        int c=j+dc[k];
                        
                        if(r>=0 && c>=0 && r<n && c<m &&grid[r][c]==1) {
                            
                            if(sety.find(ds.getParent(r*m+c)) == sety.end()) {
                                
                            count+=ds.size[ds.getParent(r*m+c)];
                            
                            sety.insert(ds.getParent(r*m+c));
                            
                            }
                        }
                    }
                    
                    ans=max(ans,count+1);
                }
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
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends