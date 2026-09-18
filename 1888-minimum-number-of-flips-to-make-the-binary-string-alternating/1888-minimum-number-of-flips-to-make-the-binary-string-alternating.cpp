class Solution {
public:
    int minFlips(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        int n = s.length();
        string s1 , s2;
        char c = '1';
        for(int i = 0 ; i < 2*n ; i++) {
            s1 += c;
            c = (c == '1') ? '0' : '1';
            s2 += c;
        }
        s = s+s;

        for(int i = 0 ; i < n ; i++) {
            if(s[i] != s1[i]) {
                cnt1++;
            }

            if(s[i] != s2[i]) {
                cnt2++;
            }
        }

        int ans = INT_MAX;
        ans = min({ans ,cnt1 , cnt2});


        for(int i = n ; i < 2*n ; i++) {
            if(s[i] != s1[i]) {
                cnt1++;
            }

            if(s[i] != s2[i]) {
                cnt2++;
            }

            if(s[i-n] != s1[i-n]) {
                cnt1--;
            }

            if(s[i-n] != s2[i-n]) {
                cnt2--;
            }
            ans = min({ans ,cnt1, cnt2});
        }
        return ans;

    }
};