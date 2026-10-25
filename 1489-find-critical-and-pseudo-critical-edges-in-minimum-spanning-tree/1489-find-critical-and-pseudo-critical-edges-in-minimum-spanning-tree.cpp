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

    bool ubs(int u, int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);

        if (ul_u == ul_v)
            return false;

        if (size[ul_u] > size[ul_v]) {
            size[ul_u] += size[ul_v];
            parent[ul_v] = ul_u;
        } else {
            size[ul_v] += size[ul_u];
            parent[ul_u] = ul_v;
        }
        return true;
    }
};

class Solution {
public:
    int kruskal(int n , vector<vector<int>> & edges , int ignore , int force) {
        DS ds(n);
        int ans = 0;
        int cnt = 0;
        if(force != -1) {
            
            ds.ubs(edges[force][0] , edges[force][1]);
            ans += edges[force][2];
            cnt++;
        }

        for(int i = 0 ; i < edges.size() ; i++) {
            if(ignore == i || force == i) continue;
            vector<int> it = edges[i];
            int u = it[0];
            int v = it[1];
            int wt = it[2];
        
            if(ds.ubs(u , v)) {
                ans += wt;
                cnt++;
            }

        }
        if(cnt != n-1) return INT_MAX;
        return ans;

       

    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int ind = 0;
        for(auto & it : edges) {
            it.push_back(ind++);
        }

        sort(edges.begin() , edges.end() , [](vector<int> & a , vector<int> & b) {
            return a[2] < b[2];
        });

        int normal = kruskal(n , edges, -1 , -1);
        vector<int> critical , pseudo_critical;

        for(int i = 0 ; i < edges.size() ; i++) {
            
            if(kruskal(n , edges , i , -1) > normal) {
                critical.push_back(edges[i][3]);
                continue;
            }

            if(kruskal(n , edges, -1 , i) == normal) {
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo_critical);
        return ans;
        
        
    }
};