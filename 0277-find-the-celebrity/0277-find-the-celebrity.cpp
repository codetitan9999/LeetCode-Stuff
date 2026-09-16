/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0 , j = n-1;

        while(i < j) {
            if(knows(i , j)) {
                i++;
            } else {
                j--;
            }
        }

        for(int val = 0 ; val < n ; val++) {
            if(val ==i) continue;
            if(knows(i , val)) return -1;
            if(!knows(val , i)) return -1;
        }
        return i;

    }
};