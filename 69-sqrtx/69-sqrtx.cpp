class Solution {
public:
    long long mySqrt(long long x) {
        long long start=0,end=x;
         long long ans;
        while(start<=end) {
            long long mid=(start+end)/2;
            if(mid*mid==x) {
                ans=mid;
                break;
            }
            else if(mid*mid>x) {
                end=mid-1;
            }
            else {
                ans=mid;
                start=mid+1;
            }       
        }
        return ans; 
    }
};