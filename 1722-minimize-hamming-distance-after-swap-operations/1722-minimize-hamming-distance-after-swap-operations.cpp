class DS {
    public:
    vector<int> size;
    vector<int> parent;
    DS(int n) {
        size.resize(n , 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DS ds(n);

        for(auto it : allowedSwaps) {
            int u = it[0];
            int v = it[1];
            ds.ubs(u , v);
        }
        unordered_map<int, unordered_map<int,int>> mp;
        for(int i = 0 ; i < n ; i++) {
            int ul_p = ds.findParent(i);
            mp[ul_p][source[i]]++;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int ul_p = ds.findParent(i);
            if(mp[ul_p][target[i]] > 0) {
                mp[ul_p][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;

    }
};