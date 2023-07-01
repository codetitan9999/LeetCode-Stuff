//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool valid(int node , int c ,int n , vector<int> & color , bool graph[101][101] ) {
        for(int i = 0 ; i < n ; i++) {
            if(node != i && graph[node][i] == 1 && color[i] == c)
            return false;
        }
        return true;
    }
    bool fun(int node , int n , vector<int> & color  , bool graph[101][101] , int m) {
        if(node == n)
        return true;
        for(int i = 0; i < m ; i++) {
            if(valid(node , i ,n, color , graph )) {
                color[node] = i;
                if(fun(node + 1  , n , color , graph , m)) return true;
                color[node] = -1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n , -1);
        return fun(0 , n , color , graph  , m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends