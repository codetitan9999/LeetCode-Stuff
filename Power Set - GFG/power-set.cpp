//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    bool checkbit(int i , int j) {
	        return (((i>>j)&1) == 1);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    
		    int n = s.length();
		    
		    for(int i = 0 ; i < (1<<n) ; i++) {
		        string str = "";
		        for(int j = 0 ; j < n ; j++) {
		            if(checkbit(i , j)) {
		                str+=s[j];
		            }
		        }
		        if(str != "")
		        ans.push_back(str);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends