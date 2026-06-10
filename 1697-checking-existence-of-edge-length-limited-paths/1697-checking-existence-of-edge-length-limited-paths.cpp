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
    static bool comp(vector<int> & v1 , vector<int> & v2) {
        return v1[2] < v2[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DS ds(n);
        vector<bool> ans(queries.size());
        vector<vector<int>> offline;
        for(int i = 0 ; i < queries.size() ; i++) {
            offline.push_back({queries[i][0] , queries[i][1] , queries[i][2], i});
        }
        sort(edgeList.begin() , edgeList.end() , comp);
        sort(offline.begin() , offline.end(), comp);
        int ind = 0;
        for(auto it : offline) {
            int u = it[0];
            int v = it[1];
            int lim = it[2];
            int index = it[3];
            while(ind < edgeList.size() && edgeList[ind][2] < lim) {
                ds.unionBySize(edgeList[ind][0] , edgeList[ind][1]);
                ind++;
            }
            ans[index] = (ds.findParent(u) == ds.findParent(v));
        }
        return ans;
    }
};