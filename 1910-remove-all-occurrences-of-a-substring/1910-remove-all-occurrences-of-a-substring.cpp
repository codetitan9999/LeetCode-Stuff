class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";

        for(char ch : s) {
            ans += ch;

            if(ans.size() >= part.size()) {
                bool match = true;
                for(int i = 0 ; i < part.size() ; i++) {
                   
                   if(ans[ans.size() - part.size() + i]  != part[i]) {
                        match = false;
                        break;
                    }
                }
                if(match) {
                    for(int i = 0 ; i < part.size() ; i++) {
                        ans.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};