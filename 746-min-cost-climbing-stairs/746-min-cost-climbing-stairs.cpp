class Solution {
public:
    int fun(vector<int> arr,int n) {
      int prev1=arr[0];
      int prev2=arr[1];
        for(int i=2;i<=n;i++) {
           int curr=arr[i]+ min(prev1,prev2);
            prev1=prev2;
            prev2=curr;
}
        return prev2;
       
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