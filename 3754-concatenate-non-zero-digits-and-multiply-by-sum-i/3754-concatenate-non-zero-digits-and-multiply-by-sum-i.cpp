class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        long long m = 1;
        while(n) {
            int r = n%10;
            if(r != 0) {
                sum += r;
                x = (r)*m + x;
                m = m*10;
            }
            n = n/10;
        }
        return 1LL* sum * x;

    }
};