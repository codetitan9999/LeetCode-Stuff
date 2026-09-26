class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        int i = 0, n = s.length();

        string ans = "";
        while(i < n) {
            
            if(s[i] == '(') {
                i++;
                string x = "";

                while(i < n && s[i] != ')') {
                    x += s[i];
                    i++;
                }
                ans += mp.count(x) ? mp[x] : "?";

            } else {
                ans += s[i];
            }
            i++;

        }
        return ans;
        
    }
};