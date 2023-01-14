//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> ans;
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        int level=0;
        vector<string> sonl;
        sonl.push_back(beginWord);
        while(!q.empty()) {
            vector<string> vec=q.front();
            q.pop();
            if(level<vec.size()) {
                level++;
                for(auto it : sonl) {
                    s.erase(it);
                }
            }
            string x=vec.back();
            if(x==endWord) {
                if(ans.size()==0) {
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()) {
                    ans.push_back(vec);
                }
            }
            string temp=x;
            for(int i=0;i<x.length();i++) {
            
                for(int ch='a';ch<='z';ch++) {
                    x[i]=ch;
                    if(s.find(x)!=s.end()) {
                        vec.push_back(x);
                        q.push(vec);
                        sonl.push_back(x);
                        vec.pop_back();
                    }
                    x=temp;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends