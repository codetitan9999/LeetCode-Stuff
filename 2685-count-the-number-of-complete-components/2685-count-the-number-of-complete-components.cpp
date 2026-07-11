class ds {
    public:
    vector<int> size , parent;
    ds(int n) {
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++) {
            parent[i] = i;
        }
    }
    int fpar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = fpar(parent[u]);
    }
    void ubs(int u , int v) {
        int ul_u = fpar(u);
        int ul_v = fpar(v);
        if(ul_u == ul_v) return ;
        if(size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        ds ds(n);
        unordered_map<int , int> edg;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            ds.ubs(u , v);
        }
        
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            edg[ds.fpar(u)]++;
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(ds.fpar(i) == i) {
                int noEdges = edg[i];
                int nodes = ds.size[i];
                int val = (nodes*(nodes-1)) / 2;
                if(noEdges == val) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};