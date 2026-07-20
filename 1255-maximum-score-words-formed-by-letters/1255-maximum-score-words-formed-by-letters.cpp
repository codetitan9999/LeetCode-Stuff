class Solution {
public:
    int ans = 0;
    void f(int ind , vector<string> & words , vector<int> & score , vector<int> & freq , int s) {
        if(ind == words.size()) {
            ans = max( ans , s);
            return;
        }

        f(ind +1 , words , score , freq , s);

        bool possible = true;
        int i = 0;
        for(i = 0 ; i < words[ind].length() ; i++) {
            if(freq[words[ind][i] -'a'] > 0) {
                freq[words[ind][i] -'a']--;
            } else {
                possible = false;
                break;
            }
        }



        if(possible) {
            f(ind +1 , words , score , freq , s+ score[ind]);
            for(int i = 0 ; i < words[ind].length() ; i++) {
                freq[words[ind][i] -'a']++;
            }
           
        } else {
            for(int j = 0 ; j < i ; j++) {
                freq[words[ind][j] -'a']++;
            }
        } 



        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ans = 0;
        vector<int> freq(26 , 0);
        for(int i = 0 ; i < letters.size(); i++) {
            freq[letters[i] - 'a']++;
        }
        vector<int> scores;
        for(auto it : words) {
            int cnt = 0;
            for(int i = 0 ; i < it.length() ; i++) {
                cnt += score[it[i]-'a'];
            }
            scores.push_back(cnt);
        }

        f(0 , words , scores ,freq ,0);


        return ans;

    }
};