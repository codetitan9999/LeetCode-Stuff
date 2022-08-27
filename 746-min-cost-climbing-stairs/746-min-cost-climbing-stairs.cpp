class Solution {
public:
    int mat[1001];
    int fun(vector<int> arr,int n) {
        if(n<0)
            return 0;
        if(n==0||n==1)
            return arr[n];
      if(mat[n]==-1)
        mat[n]=min(arr[n]+fun(arr,n-1), arr[n]+fun(arr,n-2));
        return mat[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(mat,-1,sizeof mat);
        int ans=min(fun(cost, cost.size()-1), fun(cost,cost.size()-2));
        return ans;
    }
};