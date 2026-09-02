class Solution {
public:


    /*
        use these test cases to understand 

        
            | # | `start`       | `end`         | Result  | What it teaches             |
        | - | ------------- | ------------- | ------- | --------------------------- |
        | 1 | `"RXX"`       | `"XXR"`       | `true`  | `R` can move right          |
        | 2 | `"XXR"`       | `"RXX"`       | `false` | `R` cannot move left        |
        | 3 | `"XXL"`       | `"LXX"`       | `true`  | `L` can move left           |
        | 4 | `"LXX"`       | `"XXL"`       | `false` | `L` cannot move right       |
        | 5 | `"RXL"`       | `"LXR"`       | `false` | `L` and `R` cannot cross    |
        | 6 | `"RXXL"`      | `"XRXL"`      | `true`  | Both rules working together |
        | 7 | `"X"`         | `"X"`         | `true`  | No meaningful characters    |
        | 8 | `"RXXLRXRXL"` | `"XRLXXRRLX"` | `true`  | Full case    |

    */
    bool canTransform(string start, string end) {


        int i = 0 , j = 0;
        int n = start.length();


        while( (i < n ) || (j < n)) {

            while(i < n && start[i] == 'X') i++;
            while(j < n && end[j] == 'X') j++;


            if(i == n || j == n) {
                return i == j;
            }


            if(start[i] != end[j]) return false;


            if(start[i] == 'L' && i < j) return false;


            if(start[i] == 'R' && i > j) return false;


            i++;
            j++;
        }
        return true;
        
    }
};