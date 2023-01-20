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
 

    int MaxConnection(vector<vector<int>>& grid) {
        // code here
      
        int n=grid.size();
        
        int m=grid[0].size();
        
        DisjointSet ds(n*m);
        
        int dr[]={-1,0,1,0};
        
        int dc[]={0,1,0,-1};
        
        int ans=1;
        
        for(int i=0;i<n;i++) {
            
            for(int j=0;j<m;j++) {
                
                if(grid[i][j]==1) {
                    
                    for(int row=0;row<4;row++) {
                        
                        int di=i+dr[row];
                        
                        int dj=j+dc[row];
                        
                        if(di>=0 && dj>=0 && di<n && dj<m && grid[di][dj]==1) {
                            
                            ds.UnionBySize(i*m+j, di*m+dj);
                            
                        }
                    }
                }
            }
        }
        
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