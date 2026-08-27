class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0 , right = n-1;
        int ans = n;
        while(left < n -1) {
            if(arr[left+1] >= arr[left]) left++;
            else break;
        }
        if(left == n-1) return 0;

        ans = min(ans , n-1-left);
        while(right > left+1 ) {
            if(arr[right] >= arr[right-1]) right--;
            else break;
        }
        ans = min( ans , right);


        int i = 0 , j = right;
        while( i <= left && j < n) {
            if(arr[i] <= arr[j]) {
                ans = min(ans , j-i-1);
                i++;
            } else {
                j++;
            }
        }
        return ans;

    }
};