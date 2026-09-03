class Solution {
public:
    bool f(int ind , int k , vector<int> & stones , vector<vector<int>> & dp) {
        int n = stones.size();
        if(ind == n-1) return true;
        if(k <=0) return false;
        //3 opts
        if(dp[ind][k] != -1) return dp[ind][k];

        bool ans = false;

        int minus = stones[ind] + k -1;
        int plus = stones[ind] + k+1;
        int same = stones[ind] + k;

        int minus_ub = upper_bound(stones.begin() + ind + 1 , stones.end() , minus) - stones.begin() -1;
        if(stones[minus_ub] == minus) {
            ans = ans | (f(minus_ub , k-1 ,stones , dp));
        }


        int plus_ub = upper_bound(stones.begin() + ind + 1 , stones.end() , plus) - stones.begin() -1;
        if(stones[plus_ub] == plus) {
            ans = ans | (f(plus_ub , k+1 ,stones , dp));
        }



        int same_ub = upper_bound(stones.begin() + ind + 1 , stones.end() , same) - stones.begin() -1;
        if(stones[same_ub] == same) {
            ans = ans | (f(same_ub , k ,stones , dp));
        }
        return dp[ind][k] = ans;

    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n , vector<int> (n+1 , -1)); 

        int ind = 0;
        int k = 1;
        int ub = upper_bound(stones.begin() + 1 , stones.end() , stones[0] + 1) - stones.begin();
        if(stones[ub-1] != stones[0] + 1) return false;
        ind = ub-1;
        return f(ind , k , stones , dp);
    }
};