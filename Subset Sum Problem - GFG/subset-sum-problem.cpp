//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fun(int n , vector<int> & arr , int sum , vector<vector<int>> & dp) {
        if(n==0 && sum ==0)
        return true;
        if(n!=0 && sum ==0)
        return true;
        if(sum!=0 && n==0)
        return false;
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        
        bool take = false , notake =false;
        if(arr[n-1] <= sum) {
            take = fun(n-1, arr, sum-arr[n-1], dp);
        }
        notake = fun(n-1, arr, sum, dp);
        return dp[n][sum]=take ||notake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
        return fun(n, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends