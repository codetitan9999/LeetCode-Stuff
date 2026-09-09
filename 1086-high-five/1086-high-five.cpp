class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,int> sum;
        unordered_map<int,int> cnt;

        priority_queue< pair<int,int> > pq;
        for(auto it : items) {
            pq.push({it[1] , it[0]});
        }


        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int mark = it.first;
            int id = it.second;
            if(cnt[id] == 5) continue;
            cnt[id]++;
            sum[id] += mark;
        }

        vector<vector<int>> ans;
        for(auto it : sum) {
            int id = it.first;
            int marks = it.second;
            ans.push_back({id , marks/5});
        }
        return ans;
    }
};