class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int , vector<int>> adj;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];
                long long xdistance = 1LL*(x2-x1)*(x2-x1);
                long long ydistance = 1LL*(y2-y1)*(y2-y1);
                long long r1sq = 1LL*r1*r1*1LL;
                long long r2sq = 1LL*r2*r2*1LL; 
                if(r1sq >= (xdistance + ydistance)) {
                    adj[i].push_back(j);
                }
                if(r2sq >= (xdistance + ydistance)) {
                    adj[j].push_back(i);
                }
            }
        }  
        int ans = 1;
        for(int i = 0 ; i < n ; i++) {
            int cnt = 0;
            vector<int> vis(n , 0);
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            ans = max(ans , cnt);
        }
        return ans;
    }
    
};