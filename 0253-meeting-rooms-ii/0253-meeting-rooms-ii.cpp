class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts , ends;
        for(auto it : intervals) {
            starts.push_back(it[0]);
            ends.push_back(it[1]);
        }

        sort(starts.begin() , starts.end());
        sort(ends.begin() , ends.end());
        int p1 = 0 , p2 = 0;

        int mini = 0;
        int cnt = 0;

        while(p1 < starts.size()) {
            if(starts[p1] < ends[p2]) {
                cnt++;
                p1++;
            } else {
                cnt--;
                p2++;

            }
            mini= max(mini , cnt);
        } 
        return mini;

    }
};