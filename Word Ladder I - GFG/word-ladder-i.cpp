//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({startWord,1});
        s.erase(startWord);
        while(!q.empty()) {
            string x=q.front().first;
            int val=q.front().second;
            q.pop();
            string temp=x;
            if(x==targetWord)
            return val;
            for(int i=0;i<x.length();i++) {
                
                for(char ch='a';ch<='z';ch++) {
                    
                    x[i]=ch;
                    if(s.find(x)!=s.end()) {
                        q.push({x,val+1});
                        s.erase(x);
                    }
                }
                x=temp;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends