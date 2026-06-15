class Solution {
public:
    vector<int> nnum = {0 , 1};
    vector<int> dnum = {-1 , 0};
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double , pair<int,int>> , vector<pair<double , pair<int,int>>> , greater<pair<double , pair<int,int>>>> pq;
        set<pair<int,int>> vis;
        pq.push({(double)arr[0]/(double)arr[n-1], {0 , n-1}});
        int cnt = 0;
        vis.insert({0 , n-1});
        while(!pq.empty()) {
            int num = pq.top().second.first;
            int denum = pq.top().second.second;
            double val = pq.top().first;
            pq.pop();
            cnt++;
            if(cnt == k) {
                return {arr[num] , arr[denum]};
            }
            for(int i = 0 ; i < 2 ; i++) {
                int delnum = num + nnum[i];
                int deldnum = denum + dnum[i];
                if(delnum < n && deldnum > delnum && !vis.count({delnum , deldnum})) {
                    pq.push({(double)arr[delnum]/(double)arr[deldnum] , {delnum , deldnum}});
                    vis.insert({delnum , deldnum});
                }
            }
        }
        return {};


    }
};