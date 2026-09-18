
class DS {
    public:
    vector<int> size;
    vector<int> parent;
    DS(int n) {
        size.resize(n , 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void ubs(int u , int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);
        if(ul_u == ul_v) return;

        if(size[ul_u] > size[ul_v]) {
            size[ul_u] += size[ul_v];
            parent[ul_v] = ul_u;
        } else {
            size[ul_v] += size[ul_u];
            parent[ul_u] = ul_v;
        }
    }

};

class Solution {
public:
    vector<int> delrow = {-1 , 1 , 0 , 0};
    vector<int> delcol = {0 , 0 , 1 , -1};
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        DS ds(n*m);
        unordered_map<int,int> comp;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int row = i;
                int col = j;
                if(grid[row][col] == 0) continue;
                int node = row*m + col;
                for(int k = 0 ; k < 4 ; k++) {
                    int drow = row + delrow[k];
                    int dcol = col + delcol[k];

                    if(drow <0 || dcol < 0 || drow >= n || dcol >=m || grid[drow][dcol] == 0) continue;
                    int adjNode = drow*m + dcol;
                    ds.ubs(node , adjNode);

                }
            }
        }


        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int row = i;
                int col = j;
                if(grid[row][col] == 0) continue;
                int node = row*m + col;
                comp[ds.findParent(node)] += (grid[row][col])%k;

            }
        }
        int ans = 0;
        for(auto it : comp) {
            cout<<it.second<<endl;
            if(it.second % k == 0) ans++;

        }
        return ans;



        
    }
};