class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int ind = 1;
        int i = 0;
        while(i < target.size()) {
            if(target[i] == ind) {
                ans.push_back("Push");
                i++;
                ind++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
                ind++;
            }
        }
        return ans;
        
    }
};