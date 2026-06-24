class Solution {
public:
    bool f(int ind , string & s , unordered_set<string> & st , vector<int> & dp)  {
        if(ind == s.length()) return true;
        if(dp[ind] !=-1) return dp[ind];
        for(int i = ind ; i < s.length() ; i++) {
            string x = s.substr(ind , i-ind +1);
            if(st.count(x)) {
                if(f(i +1 , s , st , dp)) {
                    return dp[ind] = true;
                } 
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin() , wordDict.end());
        vector<int> dp(s.length() , -1);
        return f(0 , s , st , dp);

        
        
    }
};