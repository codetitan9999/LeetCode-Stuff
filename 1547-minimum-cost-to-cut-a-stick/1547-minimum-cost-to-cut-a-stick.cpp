class Solution {
public:
    long long f(int i , int j , vector<long long> & arr , vector<vector<int>> & dp) {
        if(i > j) return 0;
        long long ans = 1e8;
        if(dp[i][j] !=-1) return dp[i][j];
        for(int k = i ; k <= j ; k++) {
            ans = min(ans , arr[j+1] - arr[i-1] + f(i , k-1, arr , dp) + f(k+1 , j, arr , dp));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        vector<long long> arr;
        arr.push_back(0);
        for(auto x: cuts) arr.push_back(x);
        arr.push_back(n);

        vector<vector<int>> dp(arr.size() , vector<int> (arr.size() , -1));

        return f(1 , arr.size()-2 , arr , dp);
        
    }
};