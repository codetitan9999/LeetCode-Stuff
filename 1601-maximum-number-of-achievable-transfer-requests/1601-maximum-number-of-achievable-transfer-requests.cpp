class Solution {
public:
    int res = 0;
    void f(int ind , vector<vector<int>> & reqs , vector<int> & arr, int cnt) {
        int n = arr.size();
        int m = reqs.size();

        if(ind >= m) {
            bool yes = true;
            for(int i = 0 ; i < n ; i++) {
                if(arr[i] != 0) {
                    yes = false;
                    break;
                }
            }
            if(yes) {
                res = max(res, cnt);
            }
            return;
        }

        arr[reqs[ind][0]]--;
        arr[reqs[ind][1]]++;
        f(ind+1 , reqs , arr , cnt+1);
        arr[reqs[ind][0]]++;
        arr[reqs[ind][1]]--;


        f(ind+1 , reqs , arr , cnt);



    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> arr(n , 0);
        res = 0;
        f(0 , requests ,arr , 0);
        return res;
        
    }
};