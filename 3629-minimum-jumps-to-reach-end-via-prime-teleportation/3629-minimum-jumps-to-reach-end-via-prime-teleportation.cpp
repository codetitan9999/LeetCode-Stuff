class Solution {
public:
    vector<int> isPrime;
    void Prime(int p) {
        isPrime.resize( p , 1);
        int n = isPrime.size();
        for(int i = 2 ; i*i <= n ; i++) {
            if(isPrime[i]) {
                for(int j = i*i ; j < n ; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        isPrime[0] = isPrime[1] = 0;
    }
    int minJumps(vector<int>& nums) {
        int maxi = *max_element(nums.begin() , nums.end());
        Prime(maxi+1);
        int n = nums.size();
        int steps = 0;
        queue<int> q;
        vector<int> vis(n , 0);
        vis[0] = 1;
        q.push(0);
        unordered_map<int , vector<int>> mp;
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]].push_back(i);
        }
        while(!q.empty()) {
            int sz = q.size();
            unordered_set<int> st;
            while(sz--) {
                int node = q.front();
                if(node == n-1) return steps;
                q.pop();
                int left = node - 1;
                if(left >=0 && !vis[left] ) {
                    q.push(left);
                    vis[left] = 1;
                }
                int right = node + 1;
                if(right < n && !vis[right] ) {
                    q.push(right);
                    vis[right] = 1;
                }

                if(isPrime[nums[node]] && !st.count(nums[node])) {
                    for(int i = nums[node] ; i <= maxi ; i += nums[node]) {
                        for(auto index : mp[i]) {
                            if(!vis[index]) {
                                q.push(index);
                                vis[index] = 1;
                            }
                        }
                    }
                    st.insert(nums[node]);
                }



            }
            steps++;
        }
        return 0;
        
    }
};