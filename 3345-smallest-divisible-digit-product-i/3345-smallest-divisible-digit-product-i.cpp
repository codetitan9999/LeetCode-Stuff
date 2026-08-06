class Solution {
public:
    int getProduct(int x) {
        int p = 1;
        while(x) {
            p = p * (x%10);
            x = x/10;  
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i = n ; ; i++) {
            if(getProduct(i)%t == 0) return i;
        }
        return n;
    }
};