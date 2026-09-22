class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int , vector<int>> stb;
        int n = routes.size();
        int m = routes[0].size();

        for(int i = 0 ; i < n ; i++) {

            for(auto x : routes[i]) {
                stb[x].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n , 0);

        if(!stb.count(source)) return -1;

        if(!stb.count(target)) return -1;



        for(auto it : stb[source]) {
            q.push({it, 1});
            vis[it] = 1;
        }


        while(!q.empty()) {
            int bus = q.front().first;
            int count = q.front().second;
            q.pop();
            for(auto it : routes[bus]) {
                if(it == target) return count;
                for(auto xt : stb[it]) {
                    if(!vis[xt]) {
                        q.push({xt , count+1});
                        vis[xt] = 1;
                    }
                }
            }
        }
        return -1;
    }
};