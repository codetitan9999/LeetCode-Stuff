class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        if(n < m) return ans;

        vector<int> c1(26 , 0) , c2(26 , 0);
        for(int i = 0 ; i < m ; i++) {
            c1[p[i] -'a']++;
            c2[s[i] -'a']++;
        }
        if(c1 == c2) ans.push_back(0);
        for(int i = m ; i < n ; i++) {
            c2[s[i-m] -'a']--;
            c2[s[i] -'a']++;

            if(c1 == c2) ans.push_back(i-m+1);
        }
        return ans;
    }
};