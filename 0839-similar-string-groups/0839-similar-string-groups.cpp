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
    bool check(string s1 , string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        int cnt = 0;
        for(int i = 0 ; i < s1.length() ; i++) {
            if(s1[i] != s2[i]) cnt++;
        }
        return (cnt == 2);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DS ds(n);
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                if(check(strs[i], strs[j])) {
                    ds.unionBySize(i , j);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(ds.findParent(i) == i) {
                ans++;
            }
        }
        return ans;


        
    }
};