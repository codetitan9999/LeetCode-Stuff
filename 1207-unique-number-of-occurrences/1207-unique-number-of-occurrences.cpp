class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(auto x : arr) mp[x]++;
        for(auto it : mp) {
            if(st.count(it.second)) return false;
            st.insert(it.second);

        }
        return true;
        
    }
};