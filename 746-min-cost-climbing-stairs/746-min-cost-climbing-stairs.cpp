class Solution {
public:
    int fun(vector<int> arr,int n) {
        int mat[n+1];
        mat[0]=arr[0];
        mat[1]=arr[1];
        for(int i=2;i<=n;i++) {
            mat[i]=arr[i]+ min(mat[i-1],mat[i-2]);
}
        return mat[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0)
            return 0;
        if(n==1)
            return cost[0];
        if(n==2)
            return min(cost[1],cost[0]);
        
        return min(fun(cost,n-1), fun(cost,n-2));
        
    }
};