class Solution {
public:
    long long d(vector<int>& p1 , vector<int>& p2) {
        return (p2[0]-p1[0]) *(p2[0]-p1[0]) + (p2[1] - p1[1])*(p2[1] - p1[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> k = {d(p1 , p2) , d(p1 , p3) , d(p1 , p4) , d(p2 , p3) , d(p2 , p4) , d(p3 , p4)};
        sort(k.begin() , k.end());
        return (k[0]!=0 && k[0] == k[1] && k[1] == k[2] && k[2] == k[3]  && k[4] == k[5]); 

    }
};