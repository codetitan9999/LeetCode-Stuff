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
    static bool comp(vector<int> & a , vector<int> & b) {
        return a[2] < b[2];
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        DS ds(n+1);
        int compo = n;   
        sort(edges.begin(), edges.end() , comp);
        unordered_map<int,int> c;
        for(auto it : edges) {
            if(compo > k) {
                int u = it[0];
                int v = it[1];
                int ul_u = ds.findParent(u);
                int ul_v = ds.findParent(v);
                if(ul_u != ul_v) {
                    compo--;
                    ds.ubs(u , v);
                } else {
                    continue;
                }
                int val = c[ds.findParent(u)];
                c[ds.findParent(u)] = max(val , it[2]);
            }
        }


        int ans = 0;
        for(auto it : c) {
            ans = max(ans , it.second);
        }
        return ans;
    }
};