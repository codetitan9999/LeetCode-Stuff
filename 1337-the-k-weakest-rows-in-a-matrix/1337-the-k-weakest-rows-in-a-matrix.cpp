class Solution {
public:
    int noones(vector<int> arr) {
        int low=0,high=arr.size()-1;
        int ans=arr.size();
        while(low<=high) {
            int mid=(low+high)/2;
            if(arr[mid]==0) {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
       
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> mh;
        int c=0;
        for(auto it: mat) {
            int no=noones(it);
            cout<<"no of ones in row"<<c<<"is "<<no<<endl;
            mh.push({no,c});
            c++;
            if(mh.size()>k)
                mh.pop();
            
        }
        vector<int> ans;
        while(mh.size()>0) {
            
            ans.push_back(mh.top().second);
            mh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};