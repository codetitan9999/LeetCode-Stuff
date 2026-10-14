class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin() , weight.end());
        int w = 5000;
        int ans = 0;
        for(int i = 0 ; i < weight.size() ; i++) {
            if(weight[i] <= w) {
                ans++;
                w -= weight[i];
            }
        }
        return ans;
    }
};