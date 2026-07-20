class Solution {
public:
    void f(int ind , int n ,string & temp ,  vector<string> & ans) {
        if(ind == n) {
            ans.push_back(temp);
            return;
        }

        for(char ch = 'a' ; ch <= 'c' ; ch++) {
            if(temp.empty() || temp.back() != ch) {
                temp.push_back(ch);
                f(ind+1 , n , temp , ans);
                temp.pop_back();
            }
        }

    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string temp = "";
        f(0 , n , temp , ans);
        if(ans.size() < k) return "";
        return ans[k-1];

        
    }
};