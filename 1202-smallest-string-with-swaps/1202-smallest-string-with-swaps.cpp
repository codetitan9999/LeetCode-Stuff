class DS {
    public:
    vector<int> par , size;
    DS(int n) {
        par.resize(n+1);
        size.resize(n+1 , 1);
        for(int i = 0 ; i <= n ; i++) {
            par[i] = i;
        }
    }
    int fpar(int u) {
        if(par[u] == u) return u;
        return par[u] = fpar(par[u]);
    }
    void ubs(int u , int v) {
        int ul_u = fpar(u);
        int ul_v = fpar(v);
        if(ul_u == ul_v)
        return;
        if(size[ul_u] > size[ul_v]) {
            par[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            par[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
    }

};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DS ds(n);
        for(auto it : pairs) {
            ds.ubs(it[0] , it[1]);
        }
        unordered_map<int , vector<int>> comps;
        for(int i = 0 ; i < n ; i++) {
            int ul_p = ds.fpar(i);
            comps[ul_p].push_back(i);
        }
        for(int i = 0 ; i < n ; i++) {
            if(ds.fpar(i) == i) {
                vector<char> chars;
                vector<int> indices = comps[i];
                for(auto it : indices) {
                    chars.push_back(s[it]);
                }
                sort(indices.begin(), indices.end());
                sort(chars.begin(), chars.end());
                for(int i = 0 ; i < indices.size() ; i++) {
                    s[indices[i]] = chars[i];
                }
            }
        }
        return s;
        
    }
};