class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> mp;
        int n = answerKey.length();
        int maxf = 0;
        int i = 0 ,  j= 0;
        int ans = 0;
        while(j < n ) {
            mp[answerKey[j]]++;
            maxf = max(maxf , mp[answerKey[j]]);

            while( ((j-i+1) - maxf ) > k) {
                mp[answerKey[i]]--;
                for(auto ch : {'T' , 'F'}) {
                    maxf = max(maxf , mp[ch]); 
                }
                i++;
            }


            if(((j-i+1)-maxf) <= k) ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};