class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int cnt = 1;
        int len = word.length();
        if(len <= 8) return len;
        while(len >= 8) {
            ans += cnt * 8;
            len -= 8;
            cnt++;
        }
        ans += cnt*len;
        return ans;
    }
};