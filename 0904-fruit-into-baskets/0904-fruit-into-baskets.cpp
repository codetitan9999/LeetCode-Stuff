class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int start = 0 , end = 0;
        int n = fruits.size();
        unordered_map<int, int> mp;
        int ans = 0;
        while(end < n) {
            mp[fruits[end]]++;
            while(mp.size() > 2) {
                mp[fruits[start]]--;
                if(mp[fruits[start]] == 0) mp.erase(fruits[start]);
                start++;
            }

            if(mp.size() <= 2) ans = max(ans , end - start + 1);
            end++;
        }
        return ans;
        
    }
};