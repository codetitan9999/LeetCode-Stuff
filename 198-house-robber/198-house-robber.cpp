class Solution {
public:
    int fun(vector<int> arr, int n) {
        if(n<0)
            return 0;
        // if(n==0)
        //     return arr[0];
        // if(n==1)
        //     return max(arr[0],arr[1]);
        int prev1=arr[0];
        int prev2=max(arr[1],arr[0]);
        for(int i=2;i<=n;i++) {
            int curr=max(arr[i]+prev1, prev2);
            prev1=prev2;
            prev2=curr;
        }   
        return prev2;
       
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];

        return fun(nums,n-1);
        
    }
};