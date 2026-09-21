class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int prev = 0;
        int n = values.size();
        int ans = 0;
        for(int j = 0 ; j < n ; j++) {
            ans = max(ans , prev + values[j] - j);

            prev = max(prev , values[j] + j);
        }
        return ans;
        
    }
};