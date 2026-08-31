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

    int earliestAcq(vector<vector<int>>& logs, int n) {
        DSU ds(n);
        sort(logs.begin(), logs.end());
        for(auto it : logs) {
            int a = it[0];
            int u = it[1];
            int v = it[2];
            ds.unionBySize(u , v);
            if(ds.size[ds.findParent(u)] == n) return a;

        }
        return -1;
        
    }
};