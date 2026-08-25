class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto x : nums) {
            s.insert(x);
        }
        int m = 1;
        while(true) {
            if(s.find(k*m) == s.end()) {
                return k*m;
            }
            m++;
        }
        return -1;
    }
};