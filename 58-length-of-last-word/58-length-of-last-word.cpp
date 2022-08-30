class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        int start=0, end=s.length()-1;
        while(end>=0&&s[end]==' ')
            end--;
        while(end>=0&&s[end]!=' ') {
            res++;
            end--;
        }
        return res;
    }
};