class Solution {
public:
   static bool cmp(int a,int b) {
        int x=__builtin_popcount(a);
        int y=__builtin_popcount(b);
        if(x==y)
            return a<b;
        return x<y;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};