class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        string even = "";
        string odd = "";
        vector<int> evenIndices , oddIndices;
        for(int i = 0 ; i < str.length() ; i++) {
            if(((str[i]- '0')&1)) {
                odd += str[i];
                oddIndices.push_back(i);
            } else {
                even += str[i];
                evenIndices.push_back(i);
            }
        }
        sort(even.rbegin() , even.rend());
        sort(odd.rbegin() , odd.rend());    
        for(int i = 0 ; i < oddIndices.size() ; i++) {
            str[oddIndices[i]] = odd[i];
        }
        for(int i = 0 ; i < evenIndices.size() ; i++) {
            str[evenIndices[i]] = even[i];
        }
        return stoi(str);
    }
};