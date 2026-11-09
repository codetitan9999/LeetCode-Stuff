class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        set<int> rooms;

        for(int i = 0 ; i < n ; i++) rooms.insert(i);
        vector<int> count(n , 0);
        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
        long long timer = 0LL;
        for(auto it : meetings) {
            int start = it[0];
            int end = it[1];
            timer = max(timer , 1LL*start);

            while(!pq.empty() && pq.top().first <= timer) {
                rooms.insert(pq.top().second);
                pq.pop();
            }

            if(rooms.empty()) {
                
                timer = pq.top().first;
                while(!pq.empty() && pq.top().first <= timer) {
                    rooms.insert(pq.top().second);
                    pq.pop();
                }
            }

            auto room = *rooms.begin();
            count[room]++;
            rooms.erase(room);
            pq.push({timer + end-start , room});

        }
        int maxi = *max_element(count.begin() , count.end());
        for(int i = 0 ; i < n ; i++) {
            if(count[i] == maxi) {
                return i;
            }
        }
        return -1;
        
    }
};