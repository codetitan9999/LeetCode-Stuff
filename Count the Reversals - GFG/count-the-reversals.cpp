//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char> st;
    int cc=0,co=0;
    if(s.length()%2!=0)
    return -1;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='{') {
            st.push(s[i]);
            co++;
        }
        else {
            if(st.empty()==false && st.top()=='{') {
                st.pop();
                co--;
            }
            else {
                st.push(s[i]);
                cc++;
            }
        }
      
        
    }
    int ans= (cc+1)/2;
    ans+=(co+1)/2;
    return ans;
    
}