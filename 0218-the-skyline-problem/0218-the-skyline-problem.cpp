class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for(auto it : buildings) {
            int left = it[0];
            int right = it[1];
            int height = it[2];
            events.push_back({left , -height});
            events.push_back({right , height});
        }
        sort(events.begin() , events.end());

        int i = 0, n = events.size();

        multiset<int> st;
        st.insert(0);
        int prevMax = 0;
        vector<vector<int>> ans;
        while(i < n) {

            int time = events[i].first;
            while(i < n && events[i].first == time) {
                int h = events[i].second;

                if(h < 0) {
                    st.insert(-h);
                } else {
                    st.erase(st.find(h));
                }
                i++;
            }

            int currMax = *st.rbegin();
            if(prevMax != currMax) {
                ans.push_back({time , currMax});
                prevMax = currMax;
            }
        }
        return ans;


    }
};