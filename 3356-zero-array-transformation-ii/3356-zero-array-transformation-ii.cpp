class Solution {
public:
    bool check(int mid , vector<vector<int>>& q , vector<int>& nums) {
        vector<int> diff(nums.size() , 0);
        for(int i = 0 ; i <= mid ; i++) {
            int s = q[i][0];
            int e = q[i][1];
            int val = q[i][2];
            diff[s] -= val;
            if(e < nums.size()-1) diff[e+1] += val;
        }
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += diff[i];
            diff[i] = sum;
        }
        int zeros = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if((diff[i] + nums[i]) <= 0) {
                zeros++;
            }
        }
        return zeros == nums.size();
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int zeros = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 0) zeros++;
        }
        if(zeros == nums.size()) return 0;
        int low = 0 , high = queries.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid , queries , nums)) {
                ans = mid+1;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};