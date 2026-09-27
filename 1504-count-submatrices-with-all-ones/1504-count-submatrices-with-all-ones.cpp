class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // Convert mat[i][j] into vertical height of consecutive 1s
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }

        int ans = 0;

        // Treat (i,j) as bottom-right corner
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int minHeight = INT_MAX;

                // Extend rectangle towards left
                for (int k = j; k >= 0; k--) {

                    minHeight = min(minHeight, mat[i][k]);

                    if (minHeight == 0)
                        break;

                    ans += minHeight;
                }
            }
        }

        return ans;
    }
};