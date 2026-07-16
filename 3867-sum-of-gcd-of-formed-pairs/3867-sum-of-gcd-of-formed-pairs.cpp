class Solution {
public:
    long long gcd(int x , int y) {
        //base
        if(y == 0)
            return x;
        return gcd(y, x%y);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> gcd_arr;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi , nums[i]);
            gcd_arr.push_back(gcd(maxi , nums[i]));
        }
        sort(gcd_arr.begin(), gcd_arr.end());
        int st = 0 , en = nums.size() -1;
        long long ans = 0;
        while(st < en) {
            ans += gcd(gcd_arr[st], gcd_arr[en]);
            st++;
            en--;
        }
        return ans;
    }
};