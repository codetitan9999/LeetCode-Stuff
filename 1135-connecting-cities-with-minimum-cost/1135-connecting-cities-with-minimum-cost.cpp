class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    static bool comp(vector<int> & a , vector<int> & b) {
        return a[2] < b[2];
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        DSU ds(n+1);
        int ans = 0;
        sort(connections.begin(), connections.end() , comp);
        for(auto it : connections) {
            int u = it[0];
            int v = it[1];
            int c = it[2];
            if(ds.findParent(u) != ds.findParent(v)) {
                ans += c;
                ds.unionBySize(u , v);
            }
        }

        int parent = ds.findParent(1);
        for(int i = 1 ; i <= n ; i++) {
            if(ds.findParent(i) != parent ) return -1;
        }
        return ans;
    }
};