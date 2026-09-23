class Solution {
public:
    long long f(long long mid ,vector<int>& nums) {
        long long ops = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            ops +=  ceil((double)nums[i] / mid);
        }
        return ops;
    }
    int minimumK(vector<int>& nums) {
        long long low = 1 , high = accumulate(nums.begin() , nums.end() , 0LL);
        long long ans = -1;
        while(low <= high) {
            long long mid = low + (high -low)/2;
            long long ops = f(mid , nums);
            if(ceil((double)ops/mid) > mid) {
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }

        return ans;
                                                                                                                                                                
    }
};