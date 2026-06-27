class Solution {
public:
    bool check(vector<int> & arr , int mid , int n) {
        int c = 0;
        int first = arr[0];
        int last = arr[arr.size()-1];
        if(mid <= first) return true;
        if(mid <= (n- last)) return true;
        int large = 0;
        for(int i = 0 ; i < arr.size() - 1 ; i++) {
            if(large < (arr[i+1] -arr[i])) {
                large = (arr[i+1] - arr[i]);
            }
        }  
        return (large/2) >= mid;
        

    }
    int maxDistToClosest(vector<int>& seats) {
        vector<int> v;
        for(int i = 0 ; i < seats.size() ; i++) {
            if(seats[i]) {
                v.push_back(i);
            }
        }

        int low = 1 , high = seats.size();
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(v , mid, seats.size()-1)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid -1;
            }
        }
        return ans;
        
    }
};