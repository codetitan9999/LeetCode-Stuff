class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0 , j = 0 , ans = 1;
        int mini = 1e9 , maxi = 0;
        priority_queue<pair<int,int>>  maxH;
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minH;

        while(j < n) {


            maxH.push({nums[j] , j});
            minH.push({nums[j] , j});

            int diff = abs(maxH.top().first - minH.top().first);

            while(diff > limit) {
                i++;

                while(!maxH.empty() && maxH.top().second < i) {
                    maxH.pop();
                }

                while(!minH.empty() && minH.top().second < i) {
                    minH.pop();
                }
                diff = abs(maxH.top().first - minH.top().first);

            }


            if(diff <= limit) ans = max(ans , j - i +1);
            j++;
        }
        return ans;
        
    }
};