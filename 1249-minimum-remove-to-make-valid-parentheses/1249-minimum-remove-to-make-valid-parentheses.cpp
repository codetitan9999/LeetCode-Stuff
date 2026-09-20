class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string ans = "";

        vector<int> remove(n , 0);

        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(st.empty()) {
                    remove[i] = 1;
                } else {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            remove[st.top()] = 1;
            st.pop();
        }


        for(int i = 0 ; i < n ; i++) {
            if(remove[i]) {
                continue;
            }

            ans += s[i];
        }
        return ans;
    }
};