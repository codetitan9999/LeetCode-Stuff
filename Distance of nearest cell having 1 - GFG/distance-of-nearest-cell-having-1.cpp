//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n , vector<int> (m , 0));
	    vector<vector<int>> vis(n , vector<int> (m , 0));
	    queue<pair<int,pair<int,int>>> q;
	    for(int i = 0 ; i < n ; i++) {
	        for(int j = 0 ; j < m ; j++ ) {
	            if(!vis[i][j] && grid[i][j] == 1) {
	                vis[i][j] = 1;
	                q.push({0,{i,j}});
	            }
	        }
	    }
	    int delrow[] = {0 , 1, -1 , 0};
	    int delcol[] = {-1, 0 , 0 , 1};
        while(!q.empty()) {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            ans[row][col] = steps;
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                
                if(drow >= 0 && dcol >= 0 && drow < n && dcol < m && vis[drow][dcol] == 0  && grid[drow][dcol] == 0) {
                    vis[drow][dcol] = 1;
                    q.push({steps+1 , {drow , dcol}});
                }
            }
            
            
        }
        return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends