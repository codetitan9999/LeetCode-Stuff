class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0 , o = 0;
        for(auto it : nums) {
            o ^= (it)& (~t);
            t ^= (it)& (~o);
        }
        return o;
        
    }
};