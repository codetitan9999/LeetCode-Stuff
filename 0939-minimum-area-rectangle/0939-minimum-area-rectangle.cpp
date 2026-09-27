class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {

        /*
                    x1,y2       x2,y2

                    x1,y1       x2,y1

                    if we find x1,y1 ; x2,y2 --> we should just check for other 2 , if they exist then this is a valid rectangle , find the area and minimum of all is answer
        */
        

        long long ans = INT_MAX;

        unordered_set<long long> st;
        long long base = 40001;

        for(auto it : points) {
            st.insert(it[0]*base + it[1]);
        }
        int n = points.size();

        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                vector<int> & point1 = points[i];
                vector<int> & point2 = points[j];

                if(point1[0] == point2[0] || point1[1] == point2[1]) continue;


                if(st.count(1LL*point1[0]*base + point2[1]) && st.count(1LL*point2[0] * base + point1[1])) {
                    ans = min(ans , 1LL* (abs(point2[0] - point1[0])) * (abs(point2[1] - point1[1])));
                }
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};