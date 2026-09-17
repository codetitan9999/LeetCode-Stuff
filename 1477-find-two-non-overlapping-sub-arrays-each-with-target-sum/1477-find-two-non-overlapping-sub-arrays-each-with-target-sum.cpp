class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0 , j = 0;
        int sum = 0;
        vector<int> best(n , INT_MAX);
        int bestSofar= INT_MAX;
        int ans = INT_MAX;
        while(j < n) {
            sum += arr[j];
            while(sum > target) {
                sum -= arr[i];
                i++;
            }

            while(sum == target) {
                if(i > 0 && best[i-1] != INT_MAX) {
                    int prev = best[i-1];
                    ans = min(ans , j-i+1 +prev);
                }
                bestSofar = min(bestSofar , j-i+1);
                sum -= arr[i];
                i++;
            }
            best[j] = bestSofar;
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};