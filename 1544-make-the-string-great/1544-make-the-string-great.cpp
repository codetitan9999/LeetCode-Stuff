class Solution {
public:
    bool check(char a , char b) {
        if(a == b) return false;
        if(tolower(a) == b || tolower(b) == a) return true;

        return false;
    }
    string makeGood(string s) {
        stack<char> st;


        for(int i = 0 ; i < s.length() ; i++) {
            if(st.empty() || !check(st.top() , s[i])) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }


        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
        
    }
};