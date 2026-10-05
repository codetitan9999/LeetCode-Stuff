class Solution {
public:
    struct comp {
        bool operator() (pair<int,string> &a , pair<int,string> &b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();

        vector<string> ans;
        unordered_map<int, vector<int>> adj;
        for(int i = 0 ; i < friends.size() ; i++) {
            for(auto it : friends[i]) {
                adj[it].push_back(i);
                adj[i].push_back(it);
            }
        }
        queue<int> q;
        vector<int> vis(n , 0);

        q.push(id);
        vis[id] = 1;
        int l = 0;
        vector<int> x;
        while(!q.empty()) {
            int sz = q.size();
        
            while(sz--) {
                int node = q.front();
                q.pop();

                if(l == level) {
                    x.push_back(node);
                    continue;
                }
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
            
            l++;

        }


        unordered_map<string , int> mp;
        for(auto it : x) {
        
            for(auto s : watchedVideos[it]) {
                mp[s]++;
                
            }
        }

        priority_queue<pair<int, string> , vector<pair<int, string>> , comp> pq;

        for(auto it : mp) {
            pq.push({it.second , it.first});
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};