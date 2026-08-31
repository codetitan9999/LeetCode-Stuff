class Solution {
public:
    static bool comp(vector<int> & a , vector<int> & b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> lis;
        sort(envelopes.begin() , envelopes.end() , comp);

        for(int i = 0 ; i < envelopes.size() ; i++) {
            if(lis.empty() || lis.back() < envelopes[i][1]) {
                lis.push_back(envelopes[i][1]);
            } else {
                int lb = lower_bound(lis.begin() , lis.end() , envelopes[i][1]) - lis.begin();
                lis[lb] = envelopes[i][1];
            }
        }
        return lis.size();




    }
};