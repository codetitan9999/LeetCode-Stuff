class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 0) return 0;
        if(n == 1) return stones[0];
        priority_queue<int> pq;
        for(auto it : stones) {
            pq.push(it);
        }
        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first == second) {
                continue;
            }
            pq.push(first - second);
        }
        if(pq.empty()) return 0;
        return pq.top();
        
    }
};