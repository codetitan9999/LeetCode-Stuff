class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        string ans="";
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        priority_queue<pair<int,int>> mh;
        for(auto it: m) {
            mh.push({it.second,it.first});
        }
        while(mh.size()>0) {
            char x=mh.top().second;
            int freq=mh.top().first;
            for(int i=0;i<freq;i++)
                ans.push_back(x);
            mh.pop();
        }
        return ans;
        
    }
};