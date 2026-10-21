class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);

        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string reverseVowels(string s) {
        string temp  = "";

        for(char ch : s) {
            if(isVowel(ch)) {
                temp = ch + temp;
            }
        }
        int ind = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            if(isVowel(s[i])) {
                s[i] = temp[ind++];
            }
        }
        return s;
        
        
    }
};