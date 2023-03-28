//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int fun(int ind , int par , int arr[] , int n, vector<vector<int>> &dp) {
	    if(ind == n)
	    return 0;
	    if(dp[n][par+1]!=-1)
	    return dp[n][par+1];
	    int can = 0 , cannot =0;
	    if(par == -1 || arr[ind] > arr[par]) {
	        can = arr[ind] + fun(ind+1, ind , arr, n , dp);
	    }
	       cannot = 0  + fun(ind + 1 , par, arr , n ,dp);
	   return dp[n][par+1]=max(can , cannot);
	    
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
	    return fun(0,-1,arr, n ,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends