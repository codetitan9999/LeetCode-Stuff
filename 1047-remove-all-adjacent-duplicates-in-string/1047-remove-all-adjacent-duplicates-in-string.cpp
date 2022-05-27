class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> x;
        string ans="";
        x.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(x.empty())
            {
                x.push(s[i]);
            }
            else if(x.top()==s[i])
            {
                x.pop();
            }
            else if(x.top()!=s[i])
            {
                x.push(s[i]);
            }
        }
        while(!x.empty())
        {
            ans+=x.top();
            x.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};