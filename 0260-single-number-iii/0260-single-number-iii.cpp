class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xoro = 0;
        for(auto x : nums) xoro ^= x;

        long long bit = xoro & (-xoro);
        cout<<bit<<endl;

        long long a = 0 , b = 0;

        for(auto x : nums) {
            if((x&bit)) {
                a = a ^ x;
            } else {
                b = b ^ x;
            }   
        }
        return {(int)a, (int)b};
    }
};