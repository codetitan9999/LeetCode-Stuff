class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int degree = 0;
        unordered_map<int,int> first , freq;
        int ans = n;
        for(int i = 0 ; i < n ; i++) {
            if(!first.count(nums[i])) {
                first[nums[i]] = i;
            } 

            freq[nums[i]]++;

            if(degree < freq[nums[i]]) {
                degree = freq[nums[i]];
                ans = i - first[nums[i]] +1;
            } else if(degree  ==  freq[nums[i]]) {
                ans = min(ans , i - first[nums[i]] +1);
            }
        }
        return ans;
        
    }
};