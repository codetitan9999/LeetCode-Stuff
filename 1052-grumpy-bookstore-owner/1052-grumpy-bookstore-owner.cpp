class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxGrump = 0;
        int sum = 0;


        for(int i = 0 ; i < minutes ; i++) {
            if(grumpy[i]) {
                sum += customers[i];
            }
        }
        maxGrump = max(maxGrump ,sum);


        for(int i = minutes ; i < customers.size() ; i++) {
            if(grumpy[i]) {
                sum += customers[i];
            }
            if(grumpy[i-minutes]) {
                sum -= customers[i-minutes];
            }
            maxGrump = max(maxGrump , sum);
        }

        for(int i = 0 ; i < customers.size() ; i++) {
            if(!grumpy[i]) {
                maxGrump += customers[i];
            }
        }
        return maxGrump;
    }
};