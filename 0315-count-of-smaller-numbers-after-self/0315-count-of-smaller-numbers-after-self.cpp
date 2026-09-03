class Solution {
public:
    void m(int low , int high , vector<pair<int , int>> & nums, vector<int>& ans) {
        int mid = low + (high - low) / 2;

        int left = low, right = mid+1;

        vector<pair<int,int>> temp;

        int cnt = 0;
        while(left <= mid && right <= high) {
            if(nums[left].first > nums[right].first) {
                temp.push_back(nums[right]);
                right++;
                cnt++;
            } else {
                ans[nums[left].second] += cnt;
                temp.push_back(nums[left]);
                left++;
            }
        }


        while(left <= mid) {
            ans[nums[left].second] += cnt;
            temp.push_back(nums[left]);
            left++;
        }


        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }


        for(int i = low ; i <= high ; i++) {
            nums[i] = temp[i-low]; 
        }

    }
    void ms(int low , int high , vector<pair<int,int>> & nums , vector<int>& ans) {

        if(low >= high) return;

        int mid = low + (high - low) / 2;


        ms(low , mid , nums , ans);
        ms(mid+1 , high , nums , ans);
        m(low , high , nums , ans);

    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> nums2;
        for(int i = 0 ; i < n ; i++) {
            nums2.push_back({nums[i] , i});
        }
        ms(0 , n-1 , nums2 , ans);
        return ans;

    }
};