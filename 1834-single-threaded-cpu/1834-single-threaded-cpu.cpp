class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //two min heaps
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq1;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq2;
        vector<int> ans;
        int ind = 0;
        for(auto it : tasks) {
            pq1.push({it[0] , it[1] , ind++});
        }
        long long timer = 0;
        auto top = pq1.top();
        timer = top[0];
        while(!pq1.empty()) {
            timer = pq1.top()[0];
            while(!pq1.empty() && pq1.top()[0] <= timer) {
                pq2.push({pq1.top()[1] ,  pq1.top()[2] , pq1.top()[0]});
                pq1.pop();
            }
            while(!pq2.empty()) {
                auto it = pq2.top();
                int pt = it[0];
                int et = it[2];
                int ind = it[1];
                pq2.pop();
                ans.push_back(ind);
                timer += pt ;
                while(!pq1.empty() && pq1.top()[0] <= timer) {
                    pq2.push({pq1.top()[1] , pq1.top()[2] , pq1.top()[1]});
                    pq1.pop();
                }
            }

        }
        return ans;

    }
};