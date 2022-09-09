class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        int start;
        for(auto x: t)
            m[x]++;
        int count=m.size();
        int i=0,j=0,ans=INT_MAX;
        while(j<s.length()) {
            if(m.find(s[j])!=m.end()) {
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }
            if(count>0)
                j++;
            else if(count==0) {
                while(count==0) {
                    if(ans>=j-i+1) {
                        start=i;
                        ans=j-i+1;   
                     }         
                    if(m.find(s[i])!=m.end()) {
                        m[s[i]]++;
                         if(m[s[i]]==1)
                        count++;
                        i++;
                    }
                    else {
                        i++;
                }
                   
                    
            }
               j++;
        }
        
    }
        string answer="";
        if(ans!=INT_MAX)
         answer=s.substr(start, ans);
        
        return answer;
    }
};