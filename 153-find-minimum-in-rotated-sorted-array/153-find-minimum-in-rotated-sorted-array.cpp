class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        while(low<=high) {
            int mid=low+ (high-low)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
                return nums[mid];
             else if(nums[high]>=nums[mid])
                high=mid-1;
             else if(nums[low]<=nums[mid])
                low=mid+1;
           
        }
        return -1;
    }
};