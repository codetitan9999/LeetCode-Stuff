//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        int delrow[] = {0 , 1 , 0 , -1};
        int delcol[] = {-1, 0 , 1, 0};
        while(!pq.empty()) {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow >=0 && dcol >=0 && drow < n && dcol < m ) {
                    int effort = max(d , abs(heights[drow][dcol] - heights[row][col]));
                    if(effort < dist[drow][dcol]) {
                        dist[drow][dcol] = effort;
                        pq.push({effort , {drow, dcol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends