class Solution {
public:
    bool checkDivisibility(int n) {
        long long  sum =0;
        long long mul =1;
        int temp =n;
        while(temp>0){  
            int l_digit = temp%10;
             sum += l_digit;
             mul *= l_digit;
              temp/=10;
        }
        return n%(sum+mul)==0;
    }
};