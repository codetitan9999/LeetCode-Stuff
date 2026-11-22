class Solution {
public:
    bool checkString(string s) {
        bool check = false;

        for(auto ch : s) {
            if(ch == 'b') check = true;

            if(check && ch == 'a') return false;
        }
        return true;
    }
};