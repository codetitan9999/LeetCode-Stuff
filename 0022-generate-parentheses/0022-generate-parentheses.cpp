class Solution {
public:
    void fun(int n , string s , int open , int close , vector<string> & ans) {
        if(open + close== 2*n) {
            ans.push_back(s);
            return;
        }

        if(open < n) {
            fun( n , s + "(" , open + 1 , close , ans);
        }
        if(close < open) {
            fun( n , s + ")" , open , close +1 , ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(n,"", 0 , 0 , ans);
        return ans;
        
    }
};