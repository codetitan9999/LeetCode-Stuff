class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for(char ch : s) {
            if(ch == '(') {
                st.push(score);
                score = 0;
            } else {
                int prev = st.top();
                st.pop();
                score += prev + max(score , 1);
            }
        }
        return score;
        
    }
};