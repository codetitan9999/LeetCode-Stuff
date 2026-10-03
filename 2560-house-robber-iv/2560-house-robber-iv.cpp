class Solution {
public:
    int check(vector<int> & nums , int mid) {
        int i = 0;
        int cnt = 0;
        while(i < nums.size()) {
            if(nums[i] <= mid) {
                cnt++;
                i+=2;
            } else {
                i++;
            }
        }
        return cnt;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin() , nums.end());
        int high = *max_element(nums.begin() , nums.end());

        while(low <= high) {
            int mid = low + (high -low)/2;
            int count = check(nums , mid);
            if(count >= k) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
        
    }
};