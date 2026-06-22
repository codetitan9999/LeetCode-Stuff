class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char , int> mp1 , mp2;
        mp1['b'] = 1, mp1['a'] =1 , mp1['l'] = 2 , mp1['o'] = 2 , mp1['l'] = 2 , mp1['n'] = 1;
        mp2['b'] = 0, mp2['a'] = 0 , mp2['l'] = 0 , mp2['o'] = 0 , mp2['l'] = 0 , mp2['n'] = 0;
        for(auto it : text) {
            if(mp1.count(it))
            mp2[it]++;
        }
        for(auto & it : mp2) {
            it.second /= mp1[it.first];
        }
        int mini = INT_MAX;
        for(auto it : mp2) {
            mini = min(it.second , mini);
        }
        return mini;
        
    }
};