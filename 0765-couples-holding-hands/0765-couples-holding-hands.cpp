class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int , int> mp;
        for(int i = 0 ; i < row.size() ; i++) {
            mp[row[i]] = i;
        }

        int ans = 0;


        for(int i = 0 ; i < row.size() ; i += 2) {
            int c1 = row[i];
            int c2 = row[i+1];
            int expected = row[i] ^ 1;
            if(c2 == expected) {
                continue;
            }
            ans++;
            swap(row[i+1] , row[mp[expected]]);
            mp[c2] = mp[expected];
            mp[expected] = i+1;

        }
        return ans;
    }
};