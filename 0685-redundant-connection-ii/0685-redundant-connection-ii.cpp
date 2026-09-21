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

    void unionBySize(int u , int v) {
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // a graph with no cycle (also no connected components) is a tree. 
        //In a tree , a node has exactly one parent , with mno cycle
        //Idea here is to check which node has 2 parents , store those edges, 
        //think as if one of the edge we have chosen above isnt there , even then if we find a cycle that means the ignored edge is not the prob the other one is the problem
        int n = edges.size();
        DS ds(n+1);
        vector<int> cand1 , cand2;
        vector<int> parent(n+1 , -1);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            if(parent[v] == -1) {
                parent[v] = u;

            } else {
                cand1 = {parent[v] , v};
                cand2 = {u , v};
                break;
            }
        }

        for(auto it : edges) {
            if(it == cand2) continue;
            if(ds.findPar(it[0]) == ds.findPar(it[1])) {
                if(cand1.empty()) 
                return it;
                return cand1;
            } else {
                ds.unionBySize(it[0], it[1]);
            }
        }
        return cand2;
        
    }
};