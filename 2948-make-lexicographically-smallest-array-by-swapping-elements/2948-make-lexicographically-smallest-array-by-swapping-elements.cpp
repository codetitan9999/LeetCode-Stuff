class Solution {
public:

    class DS {
        public:
        vector<int> size , parent;
        DS(int n) {
            size.resize(n+1 , 1);
            parent.resize(n+1);
            for(int i = 0 ; i <= n ; i++) {
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
    };
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DS ds(n);
        vector<pair<int,int>> np;
        for(int i = 0 ; i < n ; i++) {
            np.push_back({nums[i] , i});
        }
        sort(np.begin() , np.end());

        for(int i = 0 ; i < np.size()-1 ; i++) {

            if(abs(np[i].first - np[i+1].first) <= limit) {
                ds.unionBySize(np[i].second , np[i+1].second);
            }
        }



        unordered_map<int , vector<int>> components;

        for(int i = 0 ; i < n ; i++) {
            int root = ds.findPar(i);
            components[root].push_back(i);
        }

        for(auto it : components) {
            vector<int> indices = it.second;
            vector<int> vals;
            for(int i = 0 ; i < indices.size() ; i++) {
                vals.push_back(nums[indices[i]]);
            }

            sort(indices.begin() , indices.end());
            sort(vals.begin() , vals.end());


            for(int i = 0 ; i < indices.size() ; i++) {
                nums[indices[i]] = vals[i];
            }
        }
        return nums;

        
    }
};