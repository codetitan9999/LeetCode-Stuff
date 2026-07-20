class Solution {
public:
    void f(int ind , string & s , unordered_set<string> & st , int & res) {
        if(ind == s.length()) {
            res = max(res , (int)st.size());
            return;
        }

        for(int i = ind ; i < s.length() ; i++) {
            string x = s.substr(ind , i-ind+1);
            if(!st.count(x)) {
                st.insert(x);
                f(i+1 , s , st , res);
                st.erase(x);
            }
        }

    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int res = 0;
        f(0 , s , st , res);
        return res;
        
    }
};