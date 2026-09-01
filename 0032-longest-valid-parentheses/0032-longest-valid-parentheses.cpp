class Solution {
public:
    int longestValidParentheses(string s) {
        // insert -1 to stack first (this ensures that we cover the string from the start)
        // i.e if we have -1 on stack that means the entire string till that point is valid
        // and if -1 is removed that means we have found an invalid ) brace which we need to not include, so we should remove the length before it


        stack<int> st;
        st.push(-1);

        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {

                st.pop();

                if(st.empty()) {
                    //found an invalid brace )
                    st.push(i);
                }
                else {
                    ans = max( ans , i - st.top());
                }

            }
        }
        return ans;

    }
};