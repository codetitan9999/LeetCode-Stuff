class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int bal = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                if(bal > 0) {
                    ans += '(';
                }
                bal++;

            } else {
                bal--;
                if(bal > 0) {
                    ans += ')';
                }
            } 
        }
        return ans;
        
        
    }
};