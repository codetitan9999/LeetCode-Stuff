class Solution {
public:
   int mat[101];
    int fun(vector<int> arr, int n) {
        if(n<0)
            return 0;
        if(n==0)
            return arr[n];
        if(mat[n]==-1)
        mat[n]=max(arr[n]+fun(arr,n-2), fun(arr,n-1));
        return mat[n];
       
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        memset(mat, -1 , sizeof mat);
        return fun(nums,n-1);
        
    }
};