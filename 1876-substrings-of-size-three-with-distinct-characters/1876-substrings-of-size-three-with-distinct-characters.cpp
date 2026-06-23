class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length() < 3) return 0;
        int ans = 0;
        unordered_map<char , int> st;
        int cnt = 0;
        for(int i = 0 ; i < 3 ; i++) {
            st[s[i]]++;
        }
        if(st.size() ==3) ans++;
        cout<<ans<<" ";
        for(int i = 3 ; i < s.length() ; i++) {
            st[s[i-3]]--;
            if(st[s[i-3]] == 0) st.erase(s[i-3]);
            st[s[i]]++;
            if(st.size() == 3) ans++;
            cout<<ans<<" ";
        }
        return ans;
        
    }
};