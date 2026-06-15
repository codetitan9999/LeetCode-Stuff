class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < n ; i++) {
            int sum = 0;
            for(int j = i ; j < n ; j++) {
                sum += nums[j];
                pq.push(sum);
                cout<<sum<<" ";
            }
        }
        long long lsum = 0, rsum = 0;
        int cnt = 1;
        while(!pq.empty() && cnt <= right) {
            int val = pq.top();
            pq.pop();
            if(cnt < left) {
                lsum += val;
            }
            rsum += val;
            cnt++;
        }
        return (rsum - lsum) % mod;
    }
};