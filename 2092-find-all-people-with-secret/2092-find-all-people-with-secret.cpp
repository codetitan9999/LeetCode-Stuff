class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knows(n , 0);
        knows[0] = knows[firstPerson] = 1;
        sort(meetings.begin() , meetings.end() , [](vector<int> & a , vector<int> & b) {
            return a[2] < b[2];
        });

        int i = 0;
        int m = meetings.size();
        while( i < m ) {
            int time = meetings[i][2];
            unordered_map<int , vector<int>> adj;
            unordered_set<int> participants;
            while(i < m && time == meetings[i][2]) {
                adj[meetings[i][0]].push_back(meetings[i][1]);
                adj[meetings[i][1]].push_back(meetings[i][0]);
                participants.insert(meetings[i][0]);
                participants.insert(meetings[i][1]);
                i++;
            }
            queue<int> q;
            unordered_set<int> vis;
            for(auto it : participants) {
                if(knows[it]) {
                    q.push(it);
                    vis.insert(it);
                }
            }

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(!vis.count(it)) {
                        knows[it] = 1;
                        vis.insert(it) ;
                        q.push(it);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            if(knows[i]) {
                ans.push_back(i);
            }
        }
        return ans;

        
    }
};