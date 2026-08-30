class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        // store possible i values


        stack<int> st;


        for(int i = 0 ; i < n ; i++) {

            if(st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }



        /// check possibility for j valuesl

        int ans = 0;
        for(int i = n-1 ; i >=0 ; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                ans = max(ans , i -st.top());
                st.pop();
            }
        }
        return ans;
    }
};