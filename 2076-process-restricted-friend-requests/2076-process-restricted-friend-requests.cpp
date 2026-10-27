class DS {
public:
    vector<int> size;
    vector<int> parent;

    DS(int n) {
        size.resize(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void ubs(int u, int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);

        if (ul_u == ul_v)
            return;

        if (size[ul_u] > size[ul_v]) {
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        DS ds(n);
        for(auto req : requests) {
            int u = req[0] , v = req[1];
            int ul_u = ds.findParent(u) , ul_v = ds.findParent(v);
            if(ul_u == ul_v) {
                ans.push_back(true);
                continue;
            }
            bool isPos = true;
            for(auto res : restrictions) {
                int u2 = res[0] , v2 = res[1];

                int ul_u2 = ds.findParent(u2) , ul_v2 = ds.findParent(v2);


                if((ul_u2 == ul_u && ul_v2 == ul_v) || (ul_u2 == ul_v && ul_v2 == ul_u)) {
                    ans.push_back(false);
                    isPos = false;
                    break;
                }
                
            }
            if(isPos) {
                ds.ubs(u , v);
                ans.push_back(true);
            }

        }

        return ans;
        
    }
};