//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        vector<vector<string>> ans;
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                if(mp.find(accounts[i][j])==mp.end()) {
                    mp[accounts[i][j]]=i;
                }
                else {
                    ds.UnionBySize(mp[accounts[i][j]],i);
                }
            }
        }
        vector<string> temp[n];
        for(auto it : mp) {
            temp[ds.getParent(it.second)].push_back(it.first);
        }
        for(int i=0;i<n;i++) {
            if(temp[i].size()==0)
            continue;
            sort(temp[i].begin(),temp[i].end());
            vector<string> t;
            t.push_back(accounts[i][0]);
            for(auto it : temp[i]) {
                t.push_back(it);
            }
            ans.push_back(t);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends