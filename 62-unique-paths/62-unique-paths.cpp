class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<int> prev(n),cur(n);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0&&j==0)
                    cur[j]=1;
                else {
                        int left=0,right=0;
                        if(j>0)
                            left=cur[j-1];
                         if(i>0)
                            right=prev[j];
                        cur[j]=left+right;
                    }
        
                }
            prev=cur;
            }
        
      return prev[n-1];
        
    }
};