class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> proj;
        for(int i = 0 ; i < n ; i++) {
            proj.push_back({capital[i] , profits[i]});
        }
        sort(proj.begin() , proj.end());
        priority_queue<int> pq;
        int i = 0;
        while(k--) {
            while(i < n &&  w >= proj[i][0]) {
                pq.push(proj[i][1]);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};