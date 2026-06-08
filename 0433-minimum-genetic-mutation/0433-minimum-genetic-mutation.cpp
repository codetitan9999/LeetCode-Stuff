class Solution {
public:
    vector<char> characters = {'A' , 'C' , 'G' , 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin() , bank.end());
        if(!st.count(endGene)) return -1;
        if(startGene == endGene) return 0;
        unordered_set<string> vis;
        queue<pair<string , int>> q;
        q.push({startGene , 0});
        vis.insert(startGene);
        while(!q.empty()) {
            string x = q.front().first;
            int steps = q.front().second;
            if(endGene == x) return steps;
            q.pop();
            for(int i = 0 ; i < x.length() ; i++) { 
                char original = x[i];
                for(int j = 0 ; j < 4 ; j++) {
                    x[i] = characters[j];
                    if(st.count(x) && !vis.count(x)) {
                        vis.insert(x);
                        q.push({x, steps+1});
                    }
                }
                x[i] = original;
            }
        }
        return -1;
        
    }
};