class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<vector<int>> x(n);
        for(int i=0;i<n;i++){
            int s=0,v=nums[i];
            while(v>0){
                s+=v%10;
                v/=10;
            }
            x[i]={s,nums[i],i};
        }
        sort(x.begin(),x.end());
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int j=i,len=0;
            while(!vis[j]){
                vis[j]=1;
                j=x[j][2];
                len++;
            }
            ans+=len-1;
        }
        return ans;
    }
};