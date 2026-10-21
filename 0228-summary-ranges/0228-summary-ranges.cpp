class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int i = 0;
        while(i < n) {
            int start = nums[i];
            int next = nums[i];
            while(i < n-1 && (nums[i] == nums[i+1]-1)) {
                next = nums[i+1];
                i++;
            }
            if(start == next) ans.push_back(to_string(start));
            else ans.push_back(to_string(start) + "->" + to_string(next));
            i++;
        }
        return ans;

        
    }
};