class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n ==0) return {};
        vector<pair<int, int>> p;
        for(int i = 0 ; i < n ; i++) {
            p.push_back({arr[i] , i});
        }
        sort(p.begin() , p.end());
        vector<int> ans(n , 0);
        ans[p[0].second] = 1;
        int cnt = 1;
        for(int i = 1 ; i < n ; i++) {
            if(p[i].first == p[i-1].first) {
                ans[p[i].second] = cnt;
            } else {
                ans[p[i].second] = ++cnt;
            }

        }
        return ans;
        
    }
};