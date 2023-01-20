//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, stack<int> & st, vector<int> adj[], vector<int> & vis) {
	    vis[node]=1;
	    for(auto it : adj[node]) {
	        if(!vis[it]) {
	            dfs(it,st,adj,vis);
	        }
	    }
	    st.push(node);
	}
	void mainDfs(int node, vector<int> Revadj[], vector<int> & vis) {
	    vis[node]=1;
	    for(auto it : Revadj[node]) {
	        if(!vis[it]) {
	            mainDfs(it,Revadj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> dfsvis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++) {
            if(!dfsvis[i]) {
                dfs(i,st,adj,dfsvis);
            }
        }
        vector<int> vis(V,0);
        vector<int> Revadj[V];
        for(int i=0;i<V;i++) {
            for(auto it : adj[i]) {
                Revadj[it].push_back(i);
            }
        }
        int cnt=0;
        while(st.size()!=0) {
            int node=st.top();
            st.pop();
            if(!vis[node]) {
                mainDfs(node,Revadj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends