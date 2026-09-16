class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        deque<int> mini , maxi;


        int i = 0 , j = 0 ;

        int n = nums.size();



        while(j < n) {
            while(!mini.empty() && nums[mini.back()] > nums[j]) mini.pop_back();
            mini.push_back(j);
            while(!maxi.empty() && nums[maxi.back()] < nums[j]) maxi.pop_back();
            maxi.push_back(j);

            int diff = nums[maxi.front()] - nums[mini.front()];
            while(diff > 2) {
                i++;
                while(!maxi.empty() && maxi.front() < i) maxi.pop_front();
                while(!mini.empty() && mini.front() < i) mini.pop_front();
                diff = nums[maxi.front()] - nums[mini.front()]; 
            }

            if(diff <= 2) ans += j-i+1;
            j++;

        }
        return ans;
    }
};