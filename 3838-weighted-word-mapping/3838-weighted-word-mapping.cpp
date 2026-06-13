class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto s : words) {
            int sum = 0;
            for(auto ch : s) {
                sum += weights[ch-'a'];
            }
            sum %= 26;
            ans += 'a' + (25 - sum);
        }
        return ans;
        
    }
};