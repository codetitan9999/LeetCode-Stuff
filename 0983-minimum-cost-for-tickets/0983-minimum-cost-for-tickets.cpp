class Solution {
public:
    int f(int ind , vector<int> & days , vector<int> & costs, vector<int> & dp) {
        if(ind >= days.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        int next = ind+1;

        int oneDay = costs[0] + f(next ,days , costs, dp);

        next = lower_bound(days.begin() , days.end() , days[ind] +7) - days.begin();
        int sevenDay = costs[1] + f( next,  days , costs, dp);

        next = lower_bound(days.begin() , days.end() , days[ind] +30) - days.begin();
        int tDay = costs[2] + f(next , days , costs, dp);

        return dp[ind] = min({oneDay , sevenDay , tDay});

        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() +1  , -1);
        return f(0 , days , costs, dp);
    }
};