class Solution {
public:
    int f(int a , int b) {
        if(a == 0) return b;
        return f(b%a, a);
    }
    int gcdOfOddEvenSums(int n) {
        int s1 = 0 , s2 = 0;
        for(int i = 1 ; i <= 2*n ; i++) {
            if(i&1) {
                s1 += i;
            } else {
                s2 += i;
            }
        } 
        return f(s1 , s2);
    }
};