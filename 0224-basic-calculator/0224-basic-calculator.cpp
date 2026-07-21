class Solution {
public:
    int calculate(string s) {
        long long ans = 0 , sign = 1 , number = 0;
        stack<long long> st;
        int i = 0;
        while(i < s.length()) {
            if(s[i] == ' ') {
                i++;
                continue;
            }

            if(s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (s[i]-'0');
            } else if( s[i] == '+') {
                ans += number * sign;
                number = 0;
                sign = 1;
            } else if(s[i] == '-') {
                ans += number * sign;
                number = 0;
                sign = -1;
            } else if(s[i] == '(') {
                st.push(ans);
                ans = 0;
                number = 0;
                st.push(sign);
                sign = 1;
            } else {
                ans += number * sign;
                ans = ans * st.top();
                st.pop();
                ans += st.top();
                st.pop();
                number = 0;

            }
            i++;
        }
        return ans + number*sign;
    }
};