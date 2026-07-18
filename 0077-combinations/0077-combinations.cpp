class Solution {
public:
    void f(int ind , int j,  vector<int> & temp , int n , vector<vector<int>> & ans) {
        if(ind == temp.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = j ; i <= n ; i++) {
            temp[ind] = i;
            f(ind+1 ,i+1, temp , n , ans);
            temp[ind] = 0;

        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> temp(k , 0);
        f(0, 1,  temp , n , ans);
        return ans;


        
    }
};