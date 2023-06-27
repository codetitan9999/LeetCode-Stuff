//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        DisjointSet ds(n*n);
        int delrow[] = {0 , 0 , -1, 1};
        int delcol[] = {-1 ,1 , 0 , 0};
        for(int i = 0 ; i < n ; i++) 
        {
            for(int j = 0 ; j < n ; j++) {
                
                if(grid[i][j] == 0)
                continue;
                for(int k = 0 ; k < 4 ; k++) {
                    int row = i + delrow[k];
                    int col = j + delcol[k];
                    if(row>=0 && col >=0 && row < n && col < n && grid[row][col] == 1 ) {
                        ds.unionBySize(row*n + col , i*n + j);
                    }
                }
            }
        }
    
        int ans = 0 ;
        
        for(int i = 0 ; i < n ; i++) {
           
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 1)
                continue;
                unordered_set<int> st;
                for(int k = 0 ; k < 4 ; k++) {
                    int row = i + delrow[k];
                    int col = j + delcol[k];
                    if(row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 1) {
                        st.insert(ds.findUPar(row*n + col));
                    }
                }
                int cnt =1;
                for(auto it : st) {
                   cnt+= ds.size[it];
                }
                ans= max(ans , cnt);
                
            }
        }
        for(int i = 0 ; i < n*n ;i++) {
            ans = max( ans , ds.size[ds.findUPar(i)]);
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