class Solution {
public:
    int f(int i , int prev , vector<int>& arr1, vector<int>& arr2 , map<pair<int,int> , int> & dp) {
        
        int n = arr1.size();
        int m = arr2.size();


        if(i == n) return 0;

        if(dp.count({i, prev})) return dp[{i, prev}];

        //no swap
        int ans = INT_MAX;
        if(prev < arr1[i]) {
            int ns = f(i+1 , arr1[i] , arr1 , arr2 , dp);
            ans = min(ans , ns);
        }

        //todo , use upperbound here

        auto next = upper_bound(arr2.begin() , arr2.end() , prev);
        if(next != arr2.end()) {
            int s = f(i+1 , *next , arr1 , arr2 , dp);
            if(s != INT_MAX)
            ans = min(ans , 1 + s );
        }

        
        return dp[{i, prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin() , arr2.end());
        map<pair<int,int> , int>  dp;
        int ans = f(0 , -1 , arr1 , arr2 , dp);

      

        return ans == INT_MAX ? -1 : ans;


        
    }
};