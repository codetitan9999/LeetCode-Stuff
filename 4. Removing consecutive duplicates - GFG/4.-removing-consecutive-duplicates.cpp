// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        // Your code here
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=st.top())
            st.push(s[i]);
        }
        string x="";
        while(!st.empty())
        {
            x+=st.top();
            st.pop();
        }
        reverse(x.begin(),x.end());
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends