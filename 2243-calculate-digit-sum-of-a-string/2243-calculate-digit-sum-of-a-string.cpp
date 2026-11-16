class Solution {
public:
    string digitSum(string s, int k) {
        
        string ans = s;
        while(ans.length() > k) {
            string x = "";
            for(int i = 0 ; i < ans.length() ; i += k) {
                int val = 0;
                for(int j = i ; j < min((int)ans.length() , i+k); j++) { 
                    val += (ans[j]-'0');
                }
                x += to_string(val);
                cout<<x<<endl;
            }
            ans = x;

        }
        return ans;
    }
};