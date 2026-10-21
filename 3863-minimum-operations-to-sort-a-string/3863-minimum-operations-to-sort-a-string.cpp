class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        if(is_sorted(s.begin() , s.end())) return 0;

        if(n == 2) return -1;

        char mini = *min_element(s.begin() , s.end());
        char maxi = *max_element(s.begin() , s.end());

        if(s[0] == mini || s[n-1] == maxi) return 1;

        for(int i = 1 ; i < n-1 ; i++) {
            if(s[i] == mini || s[i] == maxi) return 2;
        }

        return 3;

        
    }
};