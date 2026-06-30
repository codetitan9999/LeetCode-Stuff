class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1 , b = -1 , c = -1;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;
            ans += 1+ min({a,b,c});
        }
        return ans;
        
    }
};