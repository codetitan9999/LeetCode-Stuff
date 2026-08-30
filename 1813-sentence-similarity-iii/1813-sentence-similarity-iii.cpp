class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1) , ss2(sentence2);


        vector<string> w1 , w2;

        string temp;

        while( ss1 >> temp) w1.push_back(temp);
        while( ss2 >> temp) w2.push_back(temp);


        if(w1.size() > w2.size()) swap(w1 , w2);

        int left = 0;
        while(left < w1.size() && w1[left] == w2[left]) left++;

        int right1 = w1.size()-1 ,  right2 = w2.size() -1;

        while(right1 >= left && w1[right1] == w2[right2]) {
            right1--;
            right2--;
        }
        return right1 < left;

        
    }
};