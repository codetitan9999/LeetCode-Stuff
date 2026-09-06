class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int p1 = 0 , p2 = n-1;

        while(p1 < p2) {
            int len = p2-p1;
            ans = max( ans , len *(min(height[p1] , height[p2])));
            if(height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
        }
        return ans;
        
    }
};