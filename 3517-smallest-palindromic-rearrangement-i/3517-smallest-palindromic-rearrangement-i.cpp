class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string left = s.substr(0 , n/2);
        sort(left.begin() , left.end());
        string right = left;
        reverse(right.begin() , right.end());
        if(n%2 == 0) {
            return left + right;
        }
        return left + s[n/2] + right;

    }
};