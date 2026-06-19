class Solution {
public:
    static bool comp(string & a , string & b) { 
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> stringNums;
        for(auto it : nums) {
            stringNums.push_back(to_string(it));
        }
        sort(stringNums.begin() , stringNums.end() , comp);
        string ans = "";
        for(auto it : stringNums) {
            ans += it;
        }
        if(ans[0] == '0') return "0";
        return ans;
        
    }
};