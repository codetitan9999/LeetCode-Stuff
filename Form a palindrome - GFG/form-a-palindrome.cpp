//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int fun(string a, string b , int p1 , int p2 ,  vector<vector<int>> &dp) {
        //base case
        if(p1 < 0 || p2 < 0)
        return 0;
        if(dp[p1][p2] != -1)
        return dp[p1][p2];
        if(a[p1] == b[p2]) {
            return dp[p1][p2]= 1 + fun(a , b , p1 - 1 , p2 - 1 ,dp ); 
        }
        else {
            return dp[p1][p2] = 0 + max(fun(a , b , p1 - 1 , p2 , dp ) , fun(a , b , p1 , p2 - 1 , dp)); 
        }
    }
    int countMin(string str){
    //complete the function here
    int n = str.length();
    string x =str;
    reverse(x.begin() , x.end());
    vector<vector<int>> dp(n  , vector<int> (n , -1));
    
    int ans = n - fun(str , x , n-1 , n-1 ,dp);
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends