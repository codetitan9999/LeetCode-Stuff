class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        int m = picture[0].size();

        vector<int> col(m , 0) , row(n , 0);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int cnt = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};