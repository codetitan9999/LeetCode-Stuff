class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<pair<int,int>> arr;
        for(int i = 0 ; i < nums1.size() ; i++) {
            arr.push_back({nums2[i] , nums1[i]});
        }
        sort(arr.rbegin(), arr.rend());
        priority_queue<int , vector<int> , greater<int>> pq;
        long long sum = 0;
        for(int i = 0 ; i < k ; i++) {
            pq.push(arr[i].second);
            sum += arr[i].second;
        }
        int mini = arr[k-1].first;
        ans = 1LL * mini * (sum);
        for(int i = k ; i < nums1.size() ; i++) {
            int last = pq.top();
            pq.pop();
            pq.push(arr[i].second);
            sum = sum - last + arr[i].second;
            mini = arr[i].first;
            ans = max(ans , 1LL * sum * mini);
        }
        return ans;


    }
};