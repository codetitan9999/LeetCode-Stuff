class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int even = (n+1)/2;

        long long ans = 0;
        int i = 0 , j =n-1;

        while(i <= j) {
            if(even ==0) break;
            if(abs(nums[i]) > abs(nums[j])) {
                ans += nums[i]*nums[i];
                even--;
                i++;
            } else {
                ans += nums[j]*nums[j];
                even--;
                j--;
            }
        }

        for(int k = i ; k <= j ; k++) {
            ans -= nums[k]*nums[k];
        }
        
        return ans;
    }
};