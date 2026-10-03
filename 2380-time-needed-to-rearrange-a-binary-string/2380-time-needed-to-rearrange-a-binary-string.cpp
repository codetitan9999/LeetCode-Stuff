class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int ans = 0, cnt = 0;
        for(auto ch : s) {
            if(ch == '0') {
                cnt++;
                
            } else if(cnt > 0){
             ans = max(cnt , ans+1);
            }
        }
        return ans;
    }
};