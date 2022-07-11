class Solution {
public:
    int findLucky(vector<int>& arr) {
        int m[501]={0};
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        int maxim=INT_MIN;
        for(int i=1;i<=500;i++)
            if(i==m[i])
                maxim=max(maxim,i);
        if(maxim==INT_MIN)
            return -1;
        return maxim;
            
        
    }
};