class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens) {
            if(it == "+") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(x+y);

            } else if(it == "-") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(x-y);


            } else if(it == "*") {

                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(x*y);

            } else if(it == "/") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(x/y);

            } else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};