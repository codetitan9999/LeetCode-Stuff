class Solution {
public:

    bool isMatch(string a, string b) {
        int n = a.length() , m = b.length();
        vector<int> prev(m+1 , false);
        vector<int> curr(m+1, false);


        


        for(int j = 0 ; j <= m ; j++) {
            bool val = true;
            for(int k = 0 ; k < j ; k++) {
                if(b[k] != '*') {
                    val = false;
                    break;
                }
            }
            prev[j] = val;
        }
        // prev[0] = false;


        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {

                if(a[i-1] == b[j-1] || (b[j-1] == '?')) {
                    curr[j] = prev[j-1];
                } else if(b[j-1] == '*') {
                    curr[j] = curr[j-1] || prev[j];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];

        
    }
};