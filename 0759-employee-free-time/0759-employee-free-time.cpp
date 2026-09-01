/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    static bool comp(Interval a , Interval b) {
        if(a.start == b.start) return a.end < b.end;

        return a.start < b.start;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> ans , intervals;
        for(auto it : schedule) {
            for(auto xt: it) {
                intervals.push_back(xt);
            }
        }
        sort(intervals.begin() , intervals.end() , comp);

        int startEnd = intervals[0].end;

        for(int i = 1 ; i < intervals.size() ; i++) {
            if(startEnd < intervals[i].start) {
                ans.push_back(Interval(startEnd , intervals[i].start));
            }
            startEnd = max(startEnd , intervals[i].end);
        }
        return ans;
        
        
    }
};