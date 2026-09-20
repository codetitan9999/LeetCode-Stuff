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
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU ds(n+m);
        unordered_set<int> st;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int row = i , col = n + j;
                if(grid[i][j] == 1) {
                    st.insert(row);
                    st.insert(col);
                    ds.unionBySize(row , col);
                }
            }
        }
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    int pare = ds.findParent(i);
                    mp[pare]++;
                }
            }
        }


        for(auto it : mp) {
            if(it.second > 1)
            ans += it.second;
        }
        return ans;
        
    }
};