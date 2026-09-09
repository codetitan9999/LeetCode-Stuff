class Solution {
public:
    const long long mod = 1e9+7;
    vector<int> nse(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1 ; i >= 0 ; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> pse(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> next , prev;
        next = nse(arr);
        prev = pse(arr);
        long long ans = 0;
        for(int i = 0 ; i < n ; i++) {
            long long left = (i - prev[i])%mod;
            long long right = (next[i] - i)%mod;
            ans = (ans + (   arr[i]  *  ( ( left * right ) % mod ) ) % mod ) % mod;
        }

        return ans;

        
    }
};