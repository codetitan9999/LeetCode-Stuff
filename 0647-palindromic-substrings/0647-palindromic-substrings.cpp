class Solution {
public:
    bool pal(string s) {
        int i = 0 , j = s.length() -1;
        while( i < j) {
            if(s[i] != s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int ind , string & s) {
        if(ind == s.length()) return 0;
        int ans =0;
        for(int i = ind ; i < s.length() ; i++) {
            string x = s.substr(ind , i -ind +1);
            if(pal(x)) {
                ans++;
            }
        }
        return ans + f(ind+1 , s);
    }
    int countSubstrings(string s) {
        return f(0 , s);
        
    }
};