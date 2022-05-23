class Solution {
public:
    static bool cmp(int x,int y)
    {
        return x>y;
    }
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int res=nums[0];
        int c=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
                c++;
            if(c==3)
            {
                res=nums[i];
            }
            
        }
        return res;
       
        
        
    }
};