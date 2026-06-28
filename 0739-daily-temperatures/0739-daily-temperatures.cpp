class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n , 0);
        stack<int> st;
        for(int i = n-1 ; i >=0 ; i--) {
            while(!st.empty() && (temp[st.top()] <= temp[i])) {
                st.pop();
            }
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
        
    }
};