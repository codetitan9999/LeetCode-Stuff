// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       int findex[26];
       for(int i=0;i<26;i++)
       findex[i]=-1;
       for(int i=0;i<S.length();i++)
       {
           if(findex[S[i]-'a']==-1)
           {
               findex[S[i]-'a']=i;
           }
           else
           {
               findex[S[i]-'a']=-2;
           }
       }
       int minim=INT_MAX;
       for(int i=0;i<26;i++)
       {
           if(findex[i]>=0)
           minim=min(minim,findex[i]);
           
       }
      if(minim==INT_MAX)
      return '$';
      return S[minim];
       
       
    }

};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends