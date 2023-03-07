//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
	        queue<char> q;
	        vector<int> v(26,0);
	        string ans="";
	        for(int i=0;i<A.length();i++) {
	               q.push(A[i]);
	               v[A[i]-'a']++;
	               while(!q.empty() && v[q.front()-'a']>1  )
	               q.pop();
	               if(q.empty())
	               ans+='#';
	               else 
	               ans+=q.front();
	        }
	        return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends