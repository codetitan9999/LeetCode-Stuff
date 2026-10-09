class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin() , courses.end() , [] (vector<int> & a , vector<int> & b) {
            return a[1] < b[1];
        });

        priority_queue<int> pq;
        int tot = 0;

        for(auto it : courses) {
            int duration = it[0];
            int last = it[1];

            if(tot + duration <= last) {
                pq.push(duration);
                tot += duration;
            } else if(!pq.empty() && pq.top() > duration) {
                tot -= pq.top();
                pq.pop();
                tot += duration;
                pq.push(duration);
            }

        }
        return pq.size();

        
    }
};