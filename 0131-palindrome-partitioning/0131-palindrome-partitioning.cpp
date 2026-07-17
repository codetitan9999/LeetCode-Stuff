class Solution {
public:
    bool isPal(string x) {
        int i = 0 , j = x.length() -1;
        while(i < j) {
            if(x[i] != x[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int ind , string s , vector<string> & temp , vector<vector<string>> & ans) {

        if(ind == s.length()) {
            ans.push_back(temp);
            return;
        }

        for(int i = ind ; i < s.length() ; i++) {
            string x = s.substr(ind , i -ind +1);
            if(isPal(x)) {
                temp.push_back(x);
                f(i+1 , s , temp , ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(0 , s, temp , ans);
        return ans;
    }
};