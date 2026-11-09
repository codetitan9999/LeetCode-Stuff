class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> st;
        for(int i = 0 ; i < times.size() ; i++) {
            times[i].push_back(i);
            st.insert(i);
        }
        sort(times.begin() , times.end());
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(auto it : times) {
            int start = it[0];
            int end = it[1];
            while(!pq.empty() && pq.top().first <= start) {
                st.insert(pq.top().second);
                pq.pop();
            }

            int seat = *st.begin();
            if(it[2] ==  targetFriend) return seat;
            st.erase(seat);
            pq.push({end , seat});
        }
        return -1;

    }
};