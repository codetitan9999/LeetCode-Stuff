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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> mat(n , vector<int> (m , 0));
        DisjointSet ds(n*m);
        int delrow[] ={0 , -1 , 0 , 1};
        int delcol[] = {1 , 0 , -1 , 0};
        vector<int> ans;
        int cnt = 0 ;
        for(auto it : operators) {
            int u =it[0];
            int v = it[1];
            if(mat[u][v] == 1) {
            ans.push_back(cnt);
            continue;
            }
            mat[u][v] = 1;
            int nodeNum = u*m + v;
            cnt++;
            for(int i = 0 ; i < 4 ; i++) {
                int drow = u + delrow[i];
                int dcol = v + delcol[i];
                int adjNode = drow*m + dcol;
                if(drow>=0 && dcol >=0 && drow < n && dcol<m && mat[drow][dcol] == 1 && ds.findUPar(adjNode) != ds.findUPar(nodeNum)) {
                    cnt--;
                    ds.unionBySize(adjNode , nodeNum);
                }
            }
            ans.push_back(cnt);
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