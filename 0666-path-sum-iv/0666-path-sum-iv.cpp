class Solution {
public:
    int dfs(int node,unordered_map<int,int> &mp,int &sum){
        if(mp.find(node)==mp.end())return 0;
        int x = node/10;
        int y = node%10;
        x++;
        y=2*(y-1)+1;
        int left = x*10+y;
        int right = x*10 +(y+1);
        if(mp.find(left)==mp.end() && mp.find(right)==mp.end()){
            sum+=mp[node];
            return 1;
        }
        int cnt = dfs(left,mp,sum)+dfs(right,mp,sum); 
        sum+=(cnt*mp[node]);
        return cnt;
    }
    int pathSum(vector<int>& nums){
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int x = nums[i]/10;
            mp[x]=nums[i]%10;
        }
        int sum=0;
        dfs(11,mp,sum);
        return sum;

    }
};