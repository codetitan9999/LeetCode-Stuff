class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m , -1);

        priority_queue<pair<int, int> , vector<pair<int,int>> , greater<pair<int,int>>> available;
        priority_queue<pair<long long, int> , vector<pair<long long,int>> , greater<pair<long long,int>>> inUse;


        for(int i = 0 ; i < n ; i++) {
            available.push({servers[i] , i});
        }

        long long timer = 0;
        int ind = 0;
        while(ind < m) {
            timer = max(timer , (long long)ind);
            while(!inUse.empty() && inUse.top().first <= timer) {
                available.push({ servers[inUse.top().second] ,inUse.top().second});
                inUse.pop();
            }

            if(available.empty()) {
                timer = inUse.top().first;
                while(!inUse.empty() && inUse.top().first <= timer) {
                    available.push({ servers[inUse.top().second] ,inUse.top().second});
                    inUse.pop();
                }
            }
            int server = available.top().second;
            available.pop();

            inUse.push({timer + tasks[ind] , server});
            ans[ind++] = server;

            
        }

        return ans;
         
    }
};