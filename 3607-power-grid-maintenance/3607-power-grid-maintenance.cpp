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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        DS ds(c+1);

        for(auto it : connections) {
            int u = it[0];
            int v = it[1];
            ds.ubs(u,v);
        }


        map<int, set<int>> components;
        int comp = 0;
        unordered_map<int,int> mp;
        for(int i = 1 ; i <= c ; i++) {
            int ul_p = ds.findParent(i);
            if(!mp.count(ul_p)) {
                mp[ul_p] = comp;
                comp++; 
            }
        }


        for(int i = 1 ; i <= c; i++) {
            int ul_p = ds.findParent(i);
            components[mp[ul_p]].insert(i);
        }



        for(auto it : queries) {
            int u = it[0];
            int v = it[1];
            int ul_p = ds.findParent(v);
            int k = mp[ul_p];
            if(u == 1) {
                if(components[k].count(v)) {
                    ans.push_back(v);
                }
                else if(!components[k].size()) {
                    ans.push_back(-1);
                    continue;
                } else {
                    ans.push_back(*components[k].begin());
                }


            } else {
                components[k].erase(v);
            }
        }
        return ans;
    }
};