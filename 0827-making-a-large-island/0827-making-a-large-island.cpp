class DS {
    public:
    vector<int> parent, size , rank;
    DS(int n) {
        parent.resize(n);
        size.resize(n , 1);
        rank.resize(n , 0);
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }
    int findPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }

    void unionBySize(int u , int v) {
        int ul_u = findPar(u);
        int ul_v = findPar(v);
        if(ul_u == ul_v) return;
        if(size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
    }
    void unionByRank(int u , int v) {
        int ul_u = findPar(u);
        int ul_v = findPar(v);
        if(ul_u == ul_v) return;
        if(rank[ul_u] == rank[ul_v]) {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        } else if(rank[ul_u] > rank[ul_v]) {
            parent[ul_v] = ul_u;
        } else {
            parent[ul_u] = ul_v;
        }
    }
};

vector<int> delrow = {-1 , 0 , 1 , 0};
vector<int> delcol = {0 , 1 , 0 , -1};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DS ds(n*m);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                
                int row = i;
                int col = j;
                if(grid[row][col] == 0) continue;

                for(int k = 0 ; k < 4 ; k++) {
                    int drow = row + delrow[k];
                    int dcol = col + delcol[k];

                    if(drow >= 0 && dcol >= 0 && drow < n && dcol < m && grid[drow][dcol] == 1) {
                        int u = row * m + col;
                        int v = drow* m + dcol;
                        ds.unionBySize(u , v);
                    }
                }
            }
        }


        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int row = i;
                int col = j;
                if(grid[row][col] == 1) continue;

                unordered_set<int> st;
                for(int k = 0 ; k < 4 ; k++) {
                    int drow = row + delrow[k];
                    int dcol = col + delcol[k];
                    if(drow >= 0 && dcol >= 0 && drow < n && dcol < m && grid[drow][dcol] == 1) {
                        int v = drow* m + dcol;

                        int ul_v = ds.findPar(v);
                        st.insert(ul_v);
                    }
                }
                int sum = 1;
                for(auto it : st) {
                    sum += ds.size[it];
                }
                ans = max( ans , sum);
            }
        }

        for(int i = 0; i < n * m; i++) {
            if(ds.findPar(i) == i) {
                ans = max(ans, ds.size[i]);
            }
        }
        return ans;

    }
};