class Solution {
public:
    string fun(int n) {
        string ans = "";
        while(n) {
            ans = ((n&1) ? '1': '0') + ans;
            n = (n>>1);
        }
        return ans;
    }
    bool queryString(string s, int n) {


        for(int i = 1 ; i <= n ; i++) {
            string x = fun(i);
            if(s.find(x) == string::npos) return false;

        }
        return true;
        
    }
};