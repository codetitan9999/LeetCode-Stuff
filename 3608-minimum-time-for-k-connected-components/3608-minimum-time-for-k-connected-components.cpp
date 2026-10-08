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
        return a[2] > b[2];
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if(edges.size() == 0) return 0;
        DS ds(n);
        sort(edges.begin() , edges.end() , comp);
        int i = 0;

        int ans = 0;
        int comp = n;

        while(i < edges.size()) {
            int timer = edges[i][2];
            if(comp >= k) {
                ans = timer;
            } else break;

            while(i < edges.size() && edges[i][2] == timer) {
                if(ds.findParent(edges[i][0]) != ds.findParent(edges[i][1])) {
                    comp--;
                    ds.ubs(edges[i][0] , edges[i][1]);
                }
                i++;
            }



        }
        if(comp >= k) ans =0;
        
        return ans;

        
    }
};