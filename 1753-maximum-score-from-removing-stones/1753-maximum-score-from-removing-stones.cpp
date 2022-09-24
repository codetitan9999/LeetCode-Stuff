class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans=0;
        while(pq.size()>=2) {
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            f-=1;s-=1;
            ans++;
            if(f!=0)
            pq.push(f);
            if(s!=0)
            pq.push(s);
        }
        return ans;
    }
};