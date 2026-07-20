class Solution {
public:
    void f(int ind , string & tiles , unordered_set<string> & st , vector<int> & used , string & temp) {

        if(ind == tiles.size()) {
            st.insert(temp);
            return;
        }

        f(ind+1 , tiles , st , used , temp);


        if(!used[ind]) {
            used[ind] = 1;
            temp.push_back(tiles[ind]);
            f(0 , tiles , st , used , temp);
            used[ind] =0;
            temp.pop_back();
        }

    }
    int numTilePossibilities(string tiles) {
        int n  = tiles.size();
        unordered_set<string> st;
        vector<int> used(n , 0);
        string temp = "";
        f(0 , tiles , st , used , temp);
        return st.size() -1 ;

    }
};