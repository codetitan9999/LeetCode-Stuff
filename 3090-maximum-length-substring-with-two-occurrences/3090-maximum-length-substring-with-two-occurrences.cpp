class Solution {
public:
    int maximumLengthSubstring(string s) {

        int start = 0 , end = 0;

        vector<int> arr(26 , 0);
        int n = s.length();
        int ans = 0;
        while(end < n) {

            arr[s[end]-'a']++;

            while(arr[s[end]-'a'] > 2) {
                arr[s[start]-'a']--;
                start++;
            }


            ans = max(ans , end - start +1);
            end++;
        }
        return ans;
        
    }
};