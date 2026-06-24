class Solution {
public:
    int f(int ind , vector<vector<int>> & jobs , vector<int>& startTime , vector<int> & dp) {
        if(ind >= jobs.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int t = 0;
        int nt = f(ind+1,  jobs, startTime, dp);
        int nextInd = lower_bound(startTime.begin() , startTime.end(), jobs[ind][1]) - startTime.begin();
        t = jobs[ind][2] + f(nextInd , jobs , startTime , dp);
        return dp[ind] = max(t , nt);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0 ; i < n ; i++) {
            jobs.push_back({startTime[i] , endTime[i], profit[i]});
        }

        sort(jobs.begin() , jobs.end());
        sort(startTime.begin() , startTime.end());
        vector<int> dp(n+1 , -1);
        return f(0 , jobs , startTime, dp);
        
    }
};