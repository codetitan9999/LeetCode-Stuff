class Solution {
public:
    vector<int> nse(vector<int> & heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);
        for(int i = n-1 ; i >=0 ; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }


    vector<int> psee(vector<int> & heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next , prev;
        next = nse(heights);
        prev = psee(heights);


        int ans = 0;

        for(int i = 0 ; i < n ; i++) {
            ans = max(ans , heights[i] * (next[i] - prev[i] - 1));
        }
        return ans;






    }
};