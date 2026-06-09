class Solution {
public:
    void dfs(char node , unordered_set<char> & vis ,unordered_map<char, vector<char>> & adj, char & ans) {
        vis.insert(node);
        if(ans > node) ans = node;
        for(auto it : adj[node]) {
            if(!vis.count(it)) {
                dfs(it , vis , adj , ans);
            }
        }
    }
        //    for(int i = 0 ; i < s1.length() ; i++) {
        //     adj[s1[i]-'a'].push_back(s2[i]-'a');
        //     adj[s2[i]-'a'].push_back(s1[i]-'a');
        // }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;
        for(int i = 0 ; i < s1.length() ; i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        for(int i = 0 ; i < baseStr.length() ; i++) {
            unordered_set<char> vis;
            char x = baseStr[i];
            dfs(baseStr[i] , vis , adj , x);
            ans.push_back(x);
        }
        return ans;
    }
};