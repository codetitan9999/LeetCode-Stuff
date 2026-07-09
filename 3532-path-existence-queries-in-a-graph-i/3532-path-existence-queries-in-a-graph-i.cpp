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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        ds ds(n);
        for(int i = 0 ; i < n-1 ; i++) {
            if((nums[i + 1] - nums[i]) <= maxDiff) {
                ds.ubs(i , i+1);
            }
        }
        for(auto q : queries) {
            int u = q[0];
            int v = q[1];
            if(ds.fpar(u) == ds.fpar(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;

    }
};