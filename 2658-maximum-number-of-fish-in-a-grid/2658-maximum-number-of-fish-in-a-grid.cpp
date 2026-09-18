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
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DS ds(n*m);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 0) continue;
                int row = i , col = j;
                int node = row*m + col;
                for(int k = 0 ; k < 4 ; k++) {
                    int drow = row + delrow[k];
                    int dcol = col + delcol[k];

                    if(drow <0 || drow >=n || dcol <0 || dcol >=m || grid[drow][dcol] == 0) continue;

                    int adjNode = drow*m + dcol;

                    ds.ubs(node , adjNode);
                }


            }
        }



        unordered_map<int, int> comp;
        for(int i = 0 ; i < n*m ; i++) {
            int node = i;

            int ul_p = ds.findParent(node);
            int row = i/m;
            int col = i%m;
            comp[ul_p] += grid[row][col];
        }

        int ans = 0;
        for(auto it : comp) {
            ans = max(ans , it.second);
        }
        return ans;
    }
};