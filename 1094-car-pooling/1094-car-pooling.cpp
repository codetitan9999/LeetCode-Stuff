class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1002 , 0);
        int maxi = 0;
        for(auto it : trips) {
            int num  = it[0];
            if(num > capacity) return false;
            int from = it[1];
            int to  = it[2];
            maxi = max(maxi , to);

            diff[from] += num;
            if(diff[from] > capacity) return false;
            diff[to] -= num;
        }

        for(int i = 1 ; i < maxi+1 ; i++) {
            diff[i] = diff[i-1] + diff[i];
            if(diff[i] > capacity) return false;
        }
        return true;




        
    }
};