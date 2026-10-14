class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char , int> mp;
        for(char ch : s) mp[ch]++;
        int ans = 0;
        int hasOdd = 0;
        for(auto it : mp) {
            if(it.second %2 == 0) {
                ans += it.second;
            } else {
                ans += it.second-1;
                hasOdd = 1;
            }
        }
        if(hasOdd) return ans+1;
        return ans;
        
    }
};