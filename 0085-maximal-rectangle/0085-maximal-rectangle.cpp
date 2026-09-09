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

    int maximalRectangle(vector<vector<char>>& matrix) {

        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> nums(m , 0);
        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                int val = matrix[i][j] - '0';
                if(val == 0) {
                    nums[j] = 0;
                } else {
                    nums[j] += 1;
                }

            }
            ans = max(ans , largestRectangleArea(nums));
        }
        return ans;
        
    }
};