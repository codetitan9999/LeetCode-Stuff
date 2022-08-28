class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int maxim=INT_MIN;
        int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        for(int i=1;i<=n;i++) {
            if(2*i<=n)
                arr[2*i]=arr[i];
            if(2*i<=n-1)
                arr[2*i+1]=arr[i]+arr[i+1];
    }
        for(int i=0;i<=n;i++)
            maxim=max(maxim,arr[i]);
        return maxim;
    }
};