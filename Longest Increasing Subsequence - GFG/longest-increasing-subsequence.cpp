//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int fun(int ind , int par , int arr[], int n,vector<vector<int>> & dp) {
        if(ind == n) {
            return 0;
        }
        if(dp[ind][par+1] !=-1)
        return dp[ind][par+1];
        int ans = 0;
        if(par == -1 || arr[ind] > arr[par]) {
            ans = max(1 + fun(ind+1, ind , arr ,n , dp) , fun(ind+1 , par , arr, n , dp));
        }
        else {
            ans = 0 +fun(ind+1 , par , arr, n , dp);
        }
        return  dp[ind][par+1] =ans;
        
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1 , vector<int> (n+1,-1));
       return fun(0, -1,a,n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends