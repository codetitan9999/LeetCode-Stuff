class Solution {
public:
    void f(int ind , int prev , vector<int>& nums , vector<vector<int>> & ans , vector<int> & temp) {
        if(temp.size() >= 2) {
            ans.push_back(temp);
        }

        unordered_set<int> st;
        for(int i = ind ; i < nums.size() ; i++) {
            if(st.count(nums[i])) continue;
            if(temp.empty() || temp.back() <= nums[i]) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                f(i +1 , i , nums , ans , temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0 , -1 , nums , ans , temp);
        return ans;

        
    }
};