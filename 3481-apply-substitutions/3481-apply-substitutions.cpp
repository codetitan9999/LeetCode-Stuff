class Solution {
public:
   unordered_map<char , string> mp;
   unordered_map<char , string> memo;

    string resolve(char ch) {
        if(memo.count(ch)) return memo[ch];

        string ans = "";

        string s = mp[ch];


        for(int i = 0 ; i < s.length() ;) {

            if(s[i] == '%') {
                ans += resolve(s[i+1]);
                i += 3;
            } else {
                ans += s[i];
                i++;    
            }
        }
        return memo[ch] = ans;


    }
    string applySubstitutions(vector<vector<string>>& rep, string t) {
        string ans = "";

        for(auto it : rep) {
            char key = it[0][0];
            string val = it[1];
            mp[key] = val;
        }


        for(int i = 0 ; i < t.length() ;) {
            if(t[i] == '%') {
                ans += resolve(t[i+1]);
                i += 3;
            } else {
                ans += t[i];
                i++;
            }
        }

        return ans;
     

    }
};