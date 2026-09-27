class Solution {
public:
    bool judgeSquareSum(int c) {

        unordered_set<long long> st;

        for(int i = 0 ; i <= sqrt(c) ; i++) {
            st.insert(1LL*i*i);
            if(st.count(1LL*c - 1LL*i*i)) return true;
       
        }

        return false;
    }
};