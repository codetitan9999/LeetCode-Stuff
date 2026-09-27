class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;
        int i = 0 , n = s.length();

        while(i < n) {

            if(s[i] == ')') {
                string x = "";
                while(!st.empty() && st.top() != '(') {
                    x += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();

                for(int k = 0 ; k < x.length() ; k++) {
                    st.push(x[k]);
                }
            } else {
                st.push(s[i]);
            }
            i++;
        }


        while(!st.empty()) {
            ans = st.top()+ ans;
            st.pop();
        }
        return ans;
        
    }
};