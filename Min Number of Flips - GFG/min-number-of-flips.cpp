// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int fun(string S, char x)
{
    int c=0;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]!=x)
        c++;
        
        if(x=='1')
        x='0';
        else
        x='1';
    }
    return c;
}
int minFlips (string S)
{
    // your code here
    return min(fun(S,'0'),fun(S,'1'));
    
}