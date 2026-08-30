class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans (n , 0);
        for(auto it : bookings) {
            int start = it[0]-1;
            int end = it[1];
            int val = it[2];
            ans[start] += val;
            if(end < n) ans[end] -= val;
        }

        for(int i = 1; i < n ; i++) {
            ans[i] = ans[i-1] + ans[i];
        }
        return ans;
        
    }
};