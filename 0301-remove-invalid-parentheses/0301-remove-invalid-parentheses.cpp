class Solution {
public:
    bool valid(string x) {
        int cnt = 0;
        for(char ch : x) {
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);


        vector<string> ans;


        while(!q.empty()) {
            int size = q.size();

            for(int i = 0 ; i < size; i++) {


                string x = q.front();
                q.pop();

                if(valid(x)) {
                    ans.push_back(x);
                }

                if(!ans.empty()) continue;



                for(int j = 0 ; j < x.length() ; j++) {
                    if(x[j] != ')' && x[j] != '(') continue;

                    string next = x.substr(0 , j) + x.substr(j+1);

                    if(!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }

            if(!ans.empty()) return ans;
        }


        return {""};
    }
};