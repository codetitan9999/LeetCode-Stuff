class Solution {
public:
    void f(int ind , string & s , unordered_set<string> & st , string temp ,   vector<string> & ans) {
        if(ind == s.length()) {
            ans.push_back(temp);
            return;
        }

        for(int i = ind ; i < s.length() ; i++) {
            string x = s.substr(ind , i - ind +1);
            if(st.count(x)) {
                f(i+1 , s , st , temp.empty() ? temp + x : temp + " " + x , ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp = "";
        unordered_set<string> st(wordDict.begin() , wordDict.end());

        f(0 , s , st , temp , ans);
        return ans;
    }
};