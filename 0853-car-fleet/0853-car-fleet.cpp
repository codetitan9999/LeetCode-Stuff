class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> arr;
        for(int i = 0 ; i < n ; i++) {
            arr.push_back({position[i] , speed[i]});
        }
        sort(arr.begin() , arr.end());
        int ans = 1;
        double prevMax = (1.0*target - 1.0*arr[n-1].first) / (1.0*arr[n-1].second);

        for(int i = n-2 ; i >= 0 ; i--) {
            double curr = (1.0*target - 1.0*arr[i].first) / (1.0*arr[i].second);
            if(curr > prevMax) {
                ans++;
                prevMax = curr;
            }
        }
        return ans;
        
    }
};