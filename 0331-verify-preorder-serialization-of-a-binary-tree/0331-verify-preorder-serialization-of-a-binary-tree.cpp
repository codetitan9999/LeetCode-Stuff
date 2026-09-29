class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        
        stringstream ss(preorder);


        string curr = "";


        while(getline(ss , curr , ',')) {
            if(slots == 0) return false;
            if(curr == "#") {
                slots--;
            } else {
                slots++;
            }
            if(slots < 0) return false;
        }
        return slots==0;
    }
};