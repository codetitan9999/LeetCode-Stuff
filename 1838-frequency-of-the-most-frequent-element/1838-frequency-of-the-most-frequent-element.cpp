class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // sum = 3 , len = 2 , (nums[i]*len - sum) > k
        long long K = (long long) k;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        long long sum  = 0;
        long long i  = 0 ,  j = 0;
        long long ans = 0;
        while(j < n) {

            while( (i < j) && (nums[j]*(j-i) - sum) > K) {
                sum -= nums[i];
                i++;
            }

            if((nums[j]*(j-i) - sum) <= K) ans = max(ans , j-i+1);
            sum += nums[j];
            j++;
        }
        return ans;
      
    }
};