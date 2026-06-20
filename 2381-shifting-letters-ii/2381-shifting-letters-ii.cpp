class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n , 0);
        for(auto it : shifts) {
            int start = it[0];
            int end = it[1];
            int dir = it[2];
            if(dir == 1) {
                diff[start]++;
                if(end < n-1) diff[end+1]--;
            } else {
                diff[start]--;
                if(end < n-1 ) diff[end+1]++;
            }
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += diff[i];
            diff[i] = sum;
        }

        for(int i = 0 ; i < n ; i++) {
            s[i] = 'a' + ((((s[i] -'a') + diff[i])%26 + 26)%26);
        }
        return s;
        
    }
};