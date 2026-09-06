class Solution {
public:
    struct comp {
        bool operator() (pair<int, string> p, pair<int, string> q) {
            if(p.first == q.first) return p.second < q.second;
            return p.first > q.first;
        }

    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;

        for(auto it : words) {
            mp[it]++;
        }

        priority_queue<pair<int , string> , vector<pair<int, string>> , comp> pq;
        for(auto it : mp) {
            pq.push({it.second , it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans(k);
        int i = k-1;
        while(!pq.empty()) {
            ans[i--] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};