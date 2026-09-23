class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        int tot = accumulate(nums.begin() , nums.end() , 0) -x;
        if(tot == 0) return n;
        if(tot < 0) return -1;
        int i = 0 , j = 0;
        int len = -1;
        while(j < n) {
            sum += nums[j];
            while(i < j && sum > tot) {
                sum -=nums[i];
                i++;
            }

            if(sum == tot) {
                len = max(len , j-i+1);
            }
            j++;
        }
        return len ==-1 ? -1 : n -len;
        
    }
};