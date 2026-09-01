class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n , 1);
        vector<int> parent(n);
        for(int i = 0 ; i < n ; i++) parent[i] = i;

        int maxi = 1 , maxInd = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if( (nums[i] % nums[j] == 0)  && ( dp[i] < dp[j] +1)) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                    if(maxi < dp[i]) {
                        maxi = dp[i];
                        maxInd = i;
                    }
                    
                }
            }
        }


        vector<int> ans(maxi , -1);
        int ind = maxInd;
        int i = maxi-1;
        while(true) {
            if(parent[ind] == ind) break;
            ans[i--] = nums[ind];
            ind = parent[ind];
            
        }
        ans[i] = nums[ind];
        return ans;


    }
};