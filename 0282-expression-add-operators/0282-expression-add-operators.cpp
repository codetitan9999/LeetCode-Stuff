class Solution {
public:
    void f(int ind , string & num, int target , string temp , long long val , long long prev ,  vector<string> & ans) {

        if(ind == num.size()) {
            if(target == val) {
                ans.push_back(temp);
            }
            return;
        }
        for(int i = ind ; i < num.length() ; i++) {
            if(i > ind && num[ind] == '0') break;
            string x = num.substr(ind , i-ind+1);
            long long curr = stoll(x);
            if(ind == 0) {
                f(i+1 , num , target , x , curr , curr , ans);

            } else {
                f(i+1 , num , target , temp + '*' + x  , val - prev + prev*curr , prev*curr , ans);
                f(i+1 , num , target , temp + '+' +x ,val + curr , curr , ans);
                f(i+1 , num , target , temp + '-' +x  , val - curr , -curr , ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp = "";
        f(0 , num , target, temp , 0, 0 , ans);
        return ans;
        
    }
};