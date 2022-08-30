class Solution {
public:
    
    int fun(vector<int> arr, int sum, int n) {
        
      int mat[n+1][sum+1];
        for(int i=0;i<=n;i++) 
            mat[i][0]=0;
        for(int j=0;j<=sum;j++) {
            mat[0][j]=INT_MAX-1;
        }
        mat[0][0]=0;
         
        // for(int j=1;j<=sum;j++) {
        //     if(j%arr[0]==0)
        //         mat[1][j]=j/arr[0];
        //     else
        //         mat[1][j]=INT_MAX-1;
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j) 
                    mat[i][j]=min(1+mat[i][j-arr[i-1]], mat[i-1][j]);
                else
                    mat[i][j]=mat[i-1][j];
        
    }
    }

        return mat[n][sum];
    }
    int coinChange(vector<int>& coins, int amount) {
       int ans=fun(coins, amount, coins.size());
        if(ans==INT_MAX-1)
            return -1;
        return ans;
    }
};