class Solution {
public:
    long long next(long long n) {
        long long ans = 0;
        while(n) {
            ans += (n%10)*(n%10);
            n = n / 10;
        }
        return ans;
    }
    bool isHappy(int n) {

        long long slow = n, fast = n;

        do {
            slow = next(slow);
            fast = next(next(fast));

        } while(slow != fast);

        return slow == 1;
        
    }
};