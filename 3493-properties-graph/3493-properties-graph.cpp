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
    bool check(vector<int> & a , vector<int> & b , int k) {
        unordered_set<int> st;
        for(auto it : a) {
            st.insert(it);
        }
        int cnt = 0;
        for(auto it : b) {
            if(st.count(it)) cnt++;
            st.erase(it);
        }
        return cnt >= k;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        DS ds(n);

        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                if(ds.findParent(i) == ds.findParent(j)) continue;
                if(check(properties[i] , properties[j] , k)) {
                    ds.ubs(i , j);
                }

            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(ds.findParent(i) == i) cnt++;

        }
        return cnt;


        
    }
};