class DS {
    public:
    vector<int> size;
    vector<int> parent;
    DS(int n) {
        size.resize(n , 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
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
    vector<int> delrow = {0 , 1 , -1 , 0};
    vector<int> delcol = {1 , 0 , 0 , -1};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        vector<vector<int>> mat(m  , vector<int> (n , 0));
        DS ds(n*m);
        int comp = 0;
        for(auto it : positions) {
            int row = it[0];
            int col = it[1];
            int node = row * n + col;
            if(mat[row][col]) {
                ans.push_back(comp);
                continue;
            }
            mat[row][col] = 1;

            comp += 1;
            unordered_set<int> st;
            for(int i = 0 ; i < 4 ; i++) {
                int drow = row + delrow[i];
                int dcol = col + delcol[i];
                if(drow < 0 || dcol < 0 || drow >=m || dcol >= n) continue;
                int adjNode = drow * n + dcol;
                if(mat[drow][dcol] == 1) {
                    st.insert(ds.findParent(adjNode));
                    ds.ubs(node , adjNode);
                }
                
            }
            comp -= st.size();
            ans.push_back(comp);
        }
        return ans;
    }
};