class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int n = ratings.size();
        int i = 1;
        while(i < n) {
            int top = 1;
            int down = 1;
            while((i < n) && (ratings[i] == ratings[i-1])) {
                ans += 1;
                i++;
            }
            while((i < n) && (ratings[i] > ratings[i-1])) {
                top++;
                ans += top;
                i++;
            }

            while((i < n) && (ratings[i] < ratings[i-1])) {
                ans += down;
                down++;
                i++;
            }
            if(down > top) ans = ans + (down-top);

        }
        return ans+1;
        
    }
};