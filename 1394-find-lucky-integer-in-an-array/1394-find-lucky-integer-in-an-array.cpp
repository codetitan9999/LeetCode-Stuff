class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto x: arr)
            m[x]++;
        int res=INT_MIN;
        for(auto x: m)
            if(x.first==x.second)
                res=max(res,x.first);
        if(res==INT_MIN)
            return -1;
        
        return res;
    }
};