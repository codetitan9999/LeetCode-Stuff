class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
        for(auto ch : s) {
            if(ch == '(') {
                st.push(score);
                score = 0;
            } else {
                int prev = st.top();
                st.pop();
                score = prev + max(1 , 2*score);
            }
        }

        return score;
        
    }
};