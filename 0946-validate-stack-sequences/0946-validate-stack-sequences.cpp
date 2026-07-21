class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int p1 = 0 , p2 = 0;
        int n = pushed.size();

        while(p1 < n && p2 < n) {
            if(pushed[p1] == popped[p2]) {
                p1++;
                p2++;
            } else if(!st.empty() && st.top() == popped[p2]){
               st.pop();
               p2++;
            } else {
                st.push(pushed[p1]);
                p1++;
            }
        }
        if(st.empty() && p2 < n) return false;
        while(!st.empty() && p2 < n) {
            if(st.top() != popped[p2]) {
                return false;
            }
            p2++;
            st.pop();

        }
        return (st.empty() &&p2==n);
    }
};