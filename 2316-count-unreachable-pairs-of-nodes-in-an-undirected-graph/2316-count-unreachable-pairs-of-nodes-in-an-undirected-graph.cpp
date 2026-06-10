class DS {
    public:
    int n;
    vector<int> size;
    vector<int> parent;
    DS(int n) {
        this->n = n;
        size.resize(n , 1);
        parent.resize(n , 0);
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionBySize(int u , int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);
        if(ul_u == ul_v) return;
        if(size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u]+= size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v]+= size[ul_u];
        }
    }

};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DS ds(n);
        long long p = (long long)n*1LL;
        long long tot = (p*(p-1)*1LL)/2;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u , v);
        }
        long long count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(ds.parent[i] == i) {
                long long x = ds.size[i];
                count += x*(x-1)/2;
            }
        }
        return tot-count;

    }
};