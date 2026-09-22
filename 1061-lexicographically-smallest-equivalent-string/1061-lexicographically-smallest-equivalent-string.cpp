class DS {
    public:
    vector<int> parent, size , rank;
    DS(int n) {
        parent.resize(n);
        size.resize(n , 1);
        rank.resize(n , 0);
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }
    int findPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }

    void ubs(int u , int v) {
        int ul_u = findPar(u);
        int ul_v = findPar(v);
        if(ul_u == ul_v) return;
        if(size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
    }
    void unionByRank(int u , int v) {
        int ul_u = findPar(u);
        int ul_v = findPar(v);
        if(ul_u == ul_v) return;
        if(rank[ul_u] == rank[ul_v]) {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        } else if(rank[ul_u] > rank[ul_v]) {
            parent[ul_v] = ul_u;
        } else {
            parent[ul_u] = ul_v;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DS ds(26);
        for(int i = 0 ; i < s1.length() ; i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            ds.ubs(u , v);
        }    

        unordered_map<int , set<int>> st;

        for(int i = 0 ; i < 26 ; i++) {
            st[ds.findPar(i)].insert(i);
        } 

        for(int i = 0 ; i < baseStr.length() ; i++) {
            int root = ds.findPar(baseStr[i]- 'a');
            set<int> k = st[root];
            baseStr[i] = 'a' + (*k.begin());
        }
        return baseStr;       
    }
};