class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin() , people.end());
        int ans = 0;
        int p1 = 0 , p2 = n-1;
        while( p1 <= p2) {
            if(people[p1] + people[p2] <= limit) {
                ans++;
                p1++;
                p2--;
            } else {
                ans++;
                p2--;
            }
        }
        return ans;

 
   
       
        
    }
};