class Solution {
public:
    const long long mod = 1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        long long ans = 0;
        
        for(int i = 0 ; i < n ; i++) {
            int j = i+1 , k = n-1;

            while(j < k) {
                long long val = (arr[i] +arr[j] + arr[k]);
                if(val < target) {
                    j++;
                } else if(val > target ) {
                    k--;
                } else {
                    if(arr[j] == arr[k]) {
                        int c = (k -j + 1);
                        ans = (ans + ((c * (c-1))/2)%mod)%mod;
                        break;
                    }
                    int left = 1 , right = 1; 
                    while(j < k && arr[j] == arr[j+1]) {
                        j++;
                        left++;
                    }
                    while(j < k && arr[k] == arr[k-1]){
                        k--;
                        right++;
                    } 

                    ans = (ans + ((left*right))%mod)%mod;
                    j++;
                    k--;
                }


            }

        }
        return ans%mod;
    }
};