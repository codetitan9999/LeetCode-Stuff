class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        stack<char> st;
        int n = s.length();
        for(int i = 0 ; i < n; ) {
            if(s[i] == '(') {
                st.push('(');
                i++;
            }
            else {
                bool validClosed = (i < n-1) && (s[i+1] == ')');
                if(st.empty()) {
                    if(validClosed) {
                       cnt += 1;
                       i +=2;
                    } else {
                        cnt += 2;
                        i++;
                    }
                } else {
                    if(validClosed) {
                        st.pop();
                        i += 2;
                    } else {
                        st.pop();
                        cnt += 1;
                        i++;
                    }
                }
            }
        }
        while(!st.empty()) {
            cnt += 2;
            st.pop();
        }
        return cnt;
    }
};