class Solution {
public:
    long long dist2(vector<int> & point1 , vector<int> & point2) {
        long long x = point2[0] - point1[0];
        long long y = point2[1] - point1[1];
        return (x*x + y*y);
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        double ans = DBL_MAX;

        map<vector<long long>, vector<pair<int,int>>> mp;
        /*
            diagonals have same mid point and same distance
            so we store all the pair of indices with 
            (xmp , ymp , dist ) -> {(i (point1) , j (point2)) ....}

        */
        int n = points.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                vector<int> & p1 = points[i];
                vector<int> & p2 = points[j];
                long long xmp = p1[0] + p2[0];
                long long ymp = p1[1] + p2[1];
                long long d = dist2(p1 , p2);

                mp[{xmp , ymp , d}].push_back({i, j});
            }
        }



        for(auto & [val , diags] : mp) {

            int m = diags.size();

            for(int i = 0 ; i < m ; i++) {
                for(int j = i+1 ; j < m ; j++) {
                    vector<int> & p1 = points[diags[i].first];
                    vector<int> & p2 = points[diags[j].first];
                    vector<int> & p3 = points[diags[j].second];

                    double side1 = sqrt(dist2(p1 , p2));
                    double side2 = sqrt(dist2(p1 , p3));

                    ans = min(ans , side1*side2);

                }
            }
        }
        return ans== DBL_MAX?0:ans;



    }
};