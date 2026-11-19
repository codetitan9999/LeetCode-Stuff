class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3)
            return 0;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> arr=nums;
        return min(abs(arr[n-1]-arr[0]),min(abs(arr[n-2]-arr[1]),min(abs(arr[n-3]-arr[0]),abs(arr[n-1]-arr[2]))));
        
        
        
    }
};