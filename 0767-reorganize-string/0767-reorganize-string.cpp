class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int , char>> pq;
        unordered_map<char , int> mp;
        for(auto it : s) {
            mp[it]++;
            if(mp[it] > (s.length()+1)/2) return "";
        }
        for(auto it : mp) {
            pq.push({it.second , it.first});
        }

        string ans = "";
        while(pq.size() >= 2) {
            auto it1 = pq.top();
            pq.pop();
            ans += it1.second;
            auto it2 = pq.top();
            ans += it2.second;
            pq.pop();
            if(it1.first-1 > 0)
            pq.push({it1.first -1 , it1.second});
            if(it2.first-1 > 0)
            pq.push({it2.first -1 , it2.second});
            
        }

        if(!pq.empty()) {
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
        
    }
};