class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        unordered_map<char , int> mp;
        for(auto it : tasks) {
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }

        while(!pq.empty()) {
            vector<int> f;
            for(int i = 0 ; i < n + 1 ; i++) {
                if(!pq.empty()) {
                    int val = pq.top();
                    pq.pop();
                    f.push_back(val-1);
                }
            }
            for(int i = 0 ; i < f.size() ; i++) {
                if(f[i] > 0) {
                    pq.push(f[i]);
                }
            }
            if(pq.empty()) {
                ans += f.size();
            } else {
                ans += (n+1);
            }


        }
        return ans;
        
    }
};