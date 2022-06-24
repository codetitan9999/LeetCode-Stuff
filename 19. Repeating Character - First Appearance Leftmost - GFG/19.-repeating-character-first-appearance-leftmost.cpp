// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function Template for C++

class Solution
{
    public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s) 
    { 
        //Your code here
        int bla=256;
       int findex[256];
      for(int i=0;i<256;i++)
      findex[i]=-1;
       int minim=INT_MAX;
       for(int i=0;i<s.length();i++)
       {
           int f=findex[s[i]];
           if(f==-1)
           findex[s[i]]=i;
           else
           {
               minim=min(minim,f);
           }
       }
       if(minim==INT_MAX)
       return -1;
       return minim;
    } 
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    Solution obj;
	    int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends