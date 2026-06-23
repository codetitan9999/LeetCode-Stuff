class Solution {
public:
    bool check(string & a , string & b) {
        unordered_set<char> st(a.begin() , a.end());
        for(int i = 0 ; i < b.length() ; i++) {
            if(st.count(b[i])) return false;
        }
        unordered_set<char> st2;
        for(int i = 0 ; i < b.length() ; i++) {
            if(st2.count(b[i])) return false;
            st2.insert(b[i]);
        }
        return true;
    }
    int f(int ind , vector<string>& arr , string temp) {
        if(ind < 0) return temp.length();
        int notake = f(ind-1 , arr , temp);
        int take = 0;
        if(check(temp , arr[ind])) {
            take = f(ind-1 , arr , temp + arr[ind]);
        }
        return max(take , notake);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        return f(arr.size()-1 , arr , temp);
        
    }
};