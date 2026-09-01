class Solution {
public:
    void f(int ind , string & s , vector<string> & ans) {
        int n = s.length();
        ans.push_back(s);
        for(int i = ind ; i < n ; i++) {
            if(s[i] >= '0' && s[i] <= '9') continue;
            s[i] = s[i] ^ 32;
            f(i+1 , s , ans);
            s[i] = s[i] ^ 32;
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        f(0 , s, ans);
        return ans;
    }
};