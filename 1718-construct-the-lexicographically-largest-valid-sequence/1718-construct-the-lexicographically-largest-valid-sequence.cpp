class Solution {
public:
    bool f(int ind , vector<int> & ans , vector<int> & used , int n) {
        if(ind == ans.size()) {
            return true;
        }
        if(ans[ind] != -1) {
            return f(ind+1 , ans , used , n);
        }
        for(int i = n ; i >= 1 ; i--) {
            if(!used[i]) {
                if(i != 1 && (ind+i < ans.size()) &&  ans[ind+i] == -1) {
                    used[i] = 1;
                    ans[ind+i] = i;
                    ans[ind] = i;
                    if(f(ind+1 , ans , used , n)) return true;
                    used[i] = 0;
                    ans[ind+i] = -1;
                    ans[ind] = -1;
                } else if (i==1) {
                    used[i] = 1;
                    ans[ind] = i;
                    if(f(ind+1 , ans , used , n)) return true;
                    used[i] = 0;
                    ans[ind] = -1;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n -1 , -1);
        vector<int> used(n+1 , 0);
        cout<<f(0 , ans , used , n )<<endl;
        return ans;
    }
};