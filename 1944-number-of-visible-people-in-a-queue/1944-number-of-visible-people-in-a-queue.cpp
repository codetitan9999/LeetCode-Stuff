class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();
        vector<int> ans(n , 0);

        stack<int> st;

        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() && heights[st.top()] <= heights[i]) {
                ans[st.top()]++;
                st.pop();
            }

            if(!st.empty() && heights[st.top()] > heights[i]) {
                ans[st.top()]++;
            }

            st.push(i);
        }
        return ans;

        
    }
};