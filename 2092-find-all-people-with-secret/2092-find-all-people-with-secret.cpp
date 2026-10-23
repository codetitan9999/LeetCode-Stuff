
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,int firstPerson) {

        // Step 1: Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int m = meetings.size();
        int i = 0;

        while (i < m) {
            int time = meetings[i][2];

            // Step 2: Build temporary graph for this timestamp
            unordered_map<int, vector<int>> adj;
            unordered_set<int> participants;

            while (i < m && meetings[i][2] == time) {
                int u = meetings[i][0];
                int v = meetings[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);

                participants.insert(u);
                participants.insert(v);

                i++;
            }

            // Step 3: Start BFS from people who already know
            queue<int> q;
            unordered_set<int> visited;

            for (int person : participants) {
                if (knows[person]) {
                    q.push(person);
                    visited.insert(person);
                }
            }

            // Step 4: Spread secret within this timestamp
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (visited.count(neighbor))
                        continue;

                    visited.insert(neighbor);
                    knows[neighbor] = true;
                    q.push(neighbor);
                }
            }

            // Temporary graph is discarded automatically
        }

        // Step 5: Collect everyone who knows the secret
        vector<int> ans;

        for (int person = 0; person < n; person++) {
            if (knows[person]) {
                ans.push_back(person);
            }
        }

        return ans;
    }
};
