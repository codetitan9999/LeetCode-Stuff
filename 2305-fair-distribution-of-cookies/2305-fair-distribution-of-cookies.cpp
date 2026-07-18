class Solution {
public:
    void f(int i , vector<int>& arr , vector<int> & temp , int & ans) {
        int n = arr.size();
        int k = temp.size();

        if(i == arr.size()) {
            ans = min(ans , *max_element(temp.begin() , temp.end()));
            return;
        }

        for(int j = 0 ; j < k ; j++) {
            temp[j] += arr[i];
            f(i+1 , arr , temp , ans);
            temp[j] -= arr[i];
        }


    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k , 0);
        int ans = INT_MAX;
        f(0 , cookies , temp , ans);
        return ans;

    }
};