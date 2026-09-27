class DetectSquares {
public:
    unordered_map<int, vector<int>> mp;
    int freq[1001][1001] = {};

    DetectSquares() {
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        mp[y].push_back(x);
        freq[x][y]++;
    }

    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];

        int ans = 0;

        for (int x2 : mp[y1]) {

            if (x1 == x2)
                continue;

            int d = abs(x2 - x1);

            // Square above
            if (y1 + d <= 1000) {
                ans += freq[x1][y1 + d] *
                       freq[x2][y1 + d];
            }

            // Square below
            if (y1 - d >= 0) {
                ans += freq[x1][y1 - d] *
                       freq[x2][y1 - d];
            }
        }

        return ans;
    }
};