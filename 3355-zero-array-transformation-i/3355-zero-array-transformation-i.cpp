class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int zeros = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 0) zeros++;
        }
        if(zeros == nums.size()) return true;
        vector<int> diff(nums.size() , 0);
        for(int i = 0 ; i < queries.size() ; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            diff[s] -= 1;
            if(e < nums.size()-1) diff[e+1] += 1;
        }
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += diff[i];
            diff[i] = sum;
        }
        zeros = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if((diff[i] + nums[i]) <= 0) {
                zeros++;
            }
        }
        return zeros == nums.size();
    }
};