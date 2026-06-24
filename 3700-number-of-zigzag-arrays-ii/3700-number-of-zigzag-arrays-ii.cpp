class Solution {
    static const long long MOD = 1e9 + 7;
    using Mat = vector<vector<long long>>;

    Mat matmul(Mat& A, Mat& B, int sz) {
        Mat C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++)
            for (int k = 0; k < sz; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < sz; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        return C;
    }

    Mat matpow(Mat M, int p, int sz) {
        Mat res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = matmul(res, M, sz);
            M = matmul(M, M, sz);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<long long> up(m);
        for (int i = 0; i < m; i++) up[i] = i;

        Mat T(m, vector<long long>(m, 0));
        for (int i = 1; i < m; i++)
            for (int k = m - i; k < m; k++)
                T[i][k] = 1;

        Mat Tn = matpow(T, n - 2, m);

        long long ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                ans = (ans + Tn[i][j] * up[j]) % MOD;

        return ans * 2 % MOD;
    }
};