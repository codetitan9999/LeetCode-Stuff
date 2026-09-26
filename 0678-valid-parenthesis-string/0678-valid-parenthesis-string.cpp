class Solution {
public:
    bool checkValidString(string s) {
        int maxi = 0, mini = 0;

        for(char ch : s) {
            if(ch == '(') {
                maxi++;
                mini++;
            } else if(ch == ')') {
                maxi--;
                mini--;
            } else {
                maxi++;
                mini--;
            }
            if(maxi < 0) return false;
            if(mini < 0) mini = 0;
        }
        return mini == 0;
    }
};