class Solution {
public:
    int f(int ind , vector<int> & nums , int k , unordered_set<int> & st) {
        if(ind == nums.size()) {
            return 1;
        }
        int nt = f(ind+1 , nums , k , st);
        int t = 0;
        if(!st.count(nums[ind] - k)) {
            st.insert(nums[ind]);
            t = f(ind+1 , nums , k , st);
            st.erase(nums[ind]);
        }
        return t+ nt;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        unordered_set<int> st;
        return f(0 , nums , k , st) -1;
        
    }
};