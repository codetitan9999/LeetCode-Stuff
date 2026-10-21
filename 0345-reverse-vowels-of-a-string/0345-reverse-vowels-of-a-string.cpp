class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);

        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string reverseVowels(string s) {
        int n = s.length();
        int p1 = 0 , p2 = n-1;


        while(p1 < p2) {
            if(!isVowel(s[p1])) p1++;
            else if(!isVowel(s[p2])) p2--;
            else {
                swap(s[p1] , s[p2]);
                p1++;
                p2--;
            }
        }
        return s;
    }
};