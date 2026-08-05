class Solution {
public:

    long long mod = 1e9+7;
    long long power(long long a , long long b) {
        if(b == 0) return 1;

        long long ans = 1;
        while(b) {
            if(b&1) {
                ans = (ans * a)%mod;
                b = b-1;
            } else {
                a = (a*a)%mod;
                b = b/2;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1) / 2;
        long long odd = n - even;
        long long ans = (power(5 , even) * power(4 , odd))%mod;
        return ans;
    }
};