class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i = 0 ; i < tickets.size() ; i++) {
            if(tickets[i] > 0) q.push(i);
        }
        int ans = 0;
        while(!q.empty()) {
            int index = q.front();
            q.pop();
         
            tickets[index]--;
            ans++;
            if(index == k && tickets[index] == 0) return ans;
 
            if(tickets[index] > 0) q.push(index);

        }
        return ans;
    }
};