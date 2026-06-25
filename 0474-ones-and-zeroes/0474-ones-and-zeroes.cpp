class Solution {
public:
    vector<vector<int>> convertString(vector<string> & strs) {
        vector<vector<int>> ans;
        for(auto s : strs) {
            int len = s.length();
            int cnt  = 0;
            for(int i = 0 ; i < s.length() ; i++) {
                if(s[i] == '0') {
                    cnt++;
                }
            } 
            ans.push_back({len - cnt, cnt});
        }
        return ans;

    }

    int f(int ind , vector<vector<int>> & st , int m , int n , vector<vector<vector<int>>> & dp ) {
        if(ind == st.size()) return 0;
        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        int nt = f(ind +1 , st , m , n, dp);
        int t = 0;
        if(m >= (st[ind][1])  && n >= (st[ind][0])) {
            t = 1 + f(ind +1 , st , m - (st[ind][1]) , n - (st[ind][0]) , dp);
        }
        return dp[ind][m][n] = max(t, nt);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> st = convertString(strs);
        vector<vector<vector<int>>> dp(strs.size() , vector<vector<int>> (m+1 , vector<int> (n+1 , -1)));
        return f(0 , st , m , n , dp);
    }
};