class Solution {
public:
    char findTheDifference(string s, string t) {
        int c1=0,c2=0;
        for(int i=0;i<s.length();i++)
        {
            c1+=(int)s[i];
        }
         for(int i=0;i<t.length();i++)
        {
            c2+=(int)t[i];
        }
        int diff=abs(c1-c2);
        return (char)diff;
        
    }
};