class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> prefix(n+1 , 0);
        int pre = 0;
        for(int i = 0 ; i < n ; i++) {
            prefix[i] = pre;
            pre += nums[i];
        }
        prefix[n] = pre;

        int ans = INT_MAX;
        for(int j = 0 ; j <= n ; j++) {


            while(!dq.empty() && (prefix[j] - prefix[dq.front()]) >= k) {
                ans = min(ans , j - dq.front());
                dq.pop_front(); 
            }

            while(!dq.empty() && prefix[dq.back()] >= prefix[j]) {
                //we want minimum value to be in our deque
                //prefix[j] - prefix[i] >= k , then prefix[i] should be as minimum as possible and as right as possible
                dq.pop_back();
            }

            dq.push_back(j);
               
        }
        return ans == INT_MAX ? -1 : ans;
        
    }
};