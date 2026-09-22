class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> d(deadends.begin() , deadends.end());

        queue<pair<string , int>> q;
        unordered_set<string> vis;
        if(d.count("0000")) return -1;
        q.push({"0000" , 0});
        vis.insert(q.front().first);
        while(!q.empty()) {
            string x = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(x == target) return steps;

            for(int i = 0 ; i < x.length() ; i++) {
                char ch = x[i];
                x[i] = '0' + ((x[i]-'0' + 1) % 10);
                if(!d.count(x) && !vis.count(x)) {
                    q.push({x , steps+1});
                    vis.insert(x);
                }
                x[i] = ch;

                x[i] = '0' + (((x[i] - '0' -1)  + 10) %10);
                if(!d.count(x) && !vis.count(x)) {
                    q.push({x , steps+1});
                    vis.insert(x);
                }
                x[i] = ch;

            }
        }
        return -1;
        
    }
};