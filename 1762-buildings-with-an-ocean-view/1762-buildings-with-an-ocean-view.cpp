class Solution {
public:
    vector<int> nge(vector<int> & h) {
        int n = h.size();
        vector<int> ans(n , n);

        stack<int> st;  
        for(int i = n - 1 ; i >= 0 ; i--) {
            while(!st.empty() && h[st.top()] < h[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;

        vector<int> ng = nge(heights);

        for(int i = 0 ; i < n ;i++) {
            if(ng[i] == n) ans.push_back(i);
        }
        return ans;
    }
};