class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long , vector<long long> , greater<long long>> pq;
        for(auto it : nums) {
            pq.push(1LL*it);
        }
        int cnt = 0; 
        while(pq.size() >= 2) {
            long long val1 = pq.top();
            if(val1 >= k) return cnt;
            pq.pop();
            long long val2 = pq.top();
            pq.pop();
            pq.push((min(val1, val2)*2 + max(val1 , val2)));
            cnt++;
        }
        return cnt;
        
    }
};