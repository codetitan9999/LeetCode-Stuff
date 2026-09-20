class Solution {
public:
    int cse(int mid , vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0 , j = m-1;
        int ans = 0;
        while(i < n && j >= 0) {
            if(matrix[i][j] > mid) {
                j--;
            } else {
                ans += j+1;
                i++;
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0], high = matrix[n-1][m-1];

        int ans = 0;
        while(low <= high) {
            int mid = low + (high-low)/2;

            int cnt = cse(mid , matrix);

            if(cnt < k) {
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};