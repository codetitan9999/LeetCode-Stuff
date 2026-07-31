class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char , int> mp;
        for(auto it : word) {
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto it : mp) {
            cout<<it.second<<endl;
            pq.push(it.second);
        }
        int ans = 0;
        int cnt = 1;
        while(!pq.empty()) {
            int sz = (pq.size() > 8) ? 8 : pq.size();
            while(sz--) {
                int val = pq.top();
                pq.pop();
                ans += val * cnt;
            }
            cnt++;
        }
        return ans;

    }
};