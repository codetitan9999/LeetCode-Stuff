class Solution {
public:
    int fun(vector<int> arr, int n) {
        if(n<0)
            return 0;
        int a[n+1];
        a[0]=arr[0];
        a[1]=max(arr[0],arr[1]);
        for(int i=2;i<=n;i++) {
            a[i]=max(arr[i]+a[i-2], a[i-1]);
        }   
        return a[n];
       
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