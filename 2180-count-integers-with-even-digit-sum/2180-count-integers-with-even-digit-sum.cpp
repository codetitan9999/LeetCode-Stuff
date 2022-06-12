class Solution {
public:
    bool check(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum%2==0;
    }
    int countEven(int num) {
        int c=0;
        for(int i=2;i<=num;i++)
            if(check(i))
                c++;
        return c;
    }
};