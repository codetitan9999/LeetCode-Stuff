class Solution {
public:
    bool check(string & s) {
        if(s[0] == '0') return false;
        int val = stoi(s);
        if(val >= 1 && val <=26) return true;

        return false;

    }
    int f(int ind , string & s, vector<int> & dp) {
        if(ind == s.length()) return 1;
        if(dp[ind] != -1) return dp[ind];
        string x = "";
        int ans = 0;
        for(int i = ind ; i < s.length() ; i++) {
            x += s[i];
            if((i-ind +1 <= 2) &&check(x)) {
                ans += f(i+1 , s, dp);
            } 
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length() , -1);
        return f(0 , s , dp);
    }
};