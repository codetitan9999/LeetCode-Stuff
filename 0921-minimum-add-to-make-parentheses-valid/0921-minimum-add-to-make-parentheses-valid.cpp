class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;

        stack<char> st;
        for(auto ch : s) {
            if(ch == '(') {
                st.push(ch);
            } else {
                if(st.empty()) ans++;
                else st.pop();
            }
        }
        while(!st.empty()) {
            ans++;
            st.pop();
        }
        return ans;
        
    }
};