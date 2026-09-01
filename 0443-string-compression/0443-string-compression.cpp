#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int cnt = 1;
        for(int i = 1 ; i < chars.size() ; i++) {
            if(chars[i-1] == chars[i]) {
                cnt++;
            } else {
                // TODO processing for single freq
                s += (chars[i-1]);
                if(cnt != 1) {
                    s += to_string(cnt); 
                } 
                cnt = 1;
            }
        }
        s += chars[chars.size()-1];
        if(cnt != 1)  s += to_string(cnt); 
        
        for(int i = 0 ; i < s.length() ; i++) {
            chars[i] = s[i];
        }
        return s.length();

   

    }
};