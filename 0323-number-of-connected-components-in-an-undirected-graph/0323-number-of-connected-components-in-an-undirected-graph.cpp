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
    int countComponents(int n, vector<vector<int>>& edges) {

        DS ds(n);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            ds.ubs(u , v);
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(ds.findParent(i) == i) ans++;
        }
        return ans;
        
    }
};