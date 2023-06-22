//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n , vector<int> (m ,0));
        int oldcolor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        int delrow[] = {-1, 0 , 1 ,0};
        int delcol[] = {0, -1 , 0 , 1};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            image[row][col] = newColor;
            q.pop();
            for(int i = 0 ; i < 4 ; i++ ) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow >= 0 && dcol >= 0 && drow < n && dcol < m  && vis[drow][dcol] == 0 && image[drow][dcol] == oldcolor) {
                    q.push({drow,dcol});
                    vis[drow][dcol] = 1;
                }
            }
            
            
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends