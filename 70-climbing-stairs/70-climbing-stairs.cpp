class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        for(int i=2;i<=n;i++)
        {
            v.push_back(v[i-1]+v[i-2]);
        }
        return v[n];
    }
};