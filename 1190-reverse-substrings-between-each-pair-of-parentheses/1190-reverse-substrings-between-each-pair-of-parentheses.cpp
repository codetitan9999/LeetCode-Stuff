class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> st;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                st.push(ans.length());

            } else if( s[i] == ')') {
                int val = st.top();
                st.pop();
                reverse(ans.begin() + val , ans.end());

            } else {
                ans += s[i];

            }
        }
        return ans;

    }
};