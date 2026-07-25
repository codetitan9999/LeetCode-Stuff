class Solution {
public:
    int maxProduct(int n) {
        int maxi = INT_MIN , secondmaxi = INT_MIN;
        while(n) {
            int x = n%10;
            if(x > maxi) {
                if(maxi != INT_MIN) secondmaxi = maxi;
                maxi = x;
            } else if(secondmaxi < x) {
                secondmaxi = x;
            }
            n = n/10;
        }
        return maxi*secondmaxi;
        
    }
};