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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DS a(n+1) , b(n+1);
        sort(edges.rbegin() , edges.rend());
        int cnt = 0;
        int compa = n, compb = n;
        for(auto it : edges) {
            int type = it[0];
            int u = it[1];
            int v = it[2];
            if(type ==3) {
                if(a.findParent(u) == a.findParent(v)) {
                    cnt++;
                    continue;
                }
                a.unionBySize(u , v);
                b.unionBySize(u , v);
                compa--;
                compb--;

            } else if(type == 2) {
                if(b.findParent(u) == b.findParent(v)) {
                    cnt++;
                    continue;
                }
                b.unionBySize(u , v);
                compb--;

            } else {
                if(a.findParent(u) == a.findParent(v)) {
                    cnt++;
                    continue;
                }
                a.unionBySize(u , v);
                compa--;
            }
        }
        if(compa != 1 || compb != 1) return -1;
        return cnt;
    }
};