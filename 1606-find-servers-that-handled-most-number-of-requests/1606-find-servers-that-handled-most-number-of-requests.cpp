class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        set<int> servers;
        for(int i = 0 ; i < k ; i++) {
            servers.insert(i);
        }
        vector<int> count(k , 0);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(int i = 0 ; i < arrival.size() ; i++) {
            int arrivalTime = arrival[i];

            while(!pq.empty() && pq.top().first <= arrivalTime) {
                servers.insert(pq.top().second);
                pq.pop();
            }
            if(servers.empty()) continue;

            auto it = servers.lower_bound(i%k);

            if(it == servers.end()) {
                it = servers.begin();
            }

            int curr = *it;

            count[curr]++;
            servers.erase(curr);
            pq.push({arrival[i] + load[i] ,curr});
            
        }
        vector<int> ans;
        int maxi = *max_element(count.begin() , count.end());
        for(int i = 0 ; i < count.size() ; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};