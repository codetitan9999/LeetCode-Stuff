#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1;
        int index = 0;
        for(int i = 1 ; i < chars.size() ; i++) {
            if(chars[i-1] == chars[i]) {
                cnt++;
            } else {
                // TODO processing for single freq
                chars[index++] = (chars[i-1]);
                if(cnt != 1) {
                    string c = to_string(cnt);
                    for(int p = 0 ; p < c.length() ; p++) {
                        chars[index++] = c[p]; 
                    }
                } 
                cnt = 1;
            }
        }
        chars[index++] = chars[chars.size()-1];
        if(cnt != 1)  {
            string c = to_string(cnt);
            for(int p = 0 ; p < c.length() ; p++) {
                chars[index++] = c[p]; 
            }
        }

        return index;

   

    }
};