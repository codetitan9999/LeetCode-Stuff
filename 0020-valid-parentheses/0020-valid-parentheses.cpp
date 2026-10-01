class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        unordered_map<char , char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        for(int i = 0 ; i < s.length() ; i++) {
            char x = s[i];
            if(x == '(' || x == '[' || x == '{') {
                st.push(x);
            }
            else if(st.size()  &&  st.top() == mp[x] ) {
                st.pop();
            }
            else {
                return false;
            }
        }
        return st.size() == 0;
    }
};