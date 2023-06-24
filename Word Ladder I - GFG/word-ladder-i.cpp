//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st;
        for(auto it : wordList) {
            st.insert(it);
        }
        st.erase(startWord);
        queue<pair<string,int>> q;
        q.push({startWord,0});
        
        while(!q.empty()) {
            string str = q.front().first;
            int steps = q.front().second;
            if(str == targetWord)
            return steps+1;
            st.erase(str);
            q.pop();
            for(int i = 0 ; i < str.length() ; i++) {
                for(char x ='a' ; x <= 'z' ; x++) {
                    char prev = str[i];
                    str[i] = x;
                    if(st.find(str) != st.end()) {
                        q.push({str, steps+1});
                    }
                    str[i] = prev;
                }
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