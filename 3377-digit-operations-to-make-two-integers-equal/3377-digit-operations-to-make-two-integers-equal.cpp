class Solution {
public:
    bool isPrime(int x) {
        if(x <= 1) return false;
        for(int i = 2 ; i*i <= x ; i++) {
            if(x%i == 0) {
                return false;
            }
        }
        return true;
    }
    int minOperations(int n, int m) {
        if(isPrime(n) || isPrime(m)) return -1;

        int maxi = 1;
        for(int i = 0 ; i <= to_string(n).length() ; i++) maxi *= 10;

        vector<int> dist(maxi , INT_MAX);

        dist[n] = n;
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        pq.push({n , n});


        while(!pq.empty()) {
            int val = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            if(dist[node] != val) continue;
            if(node == m) return val;

            string x = to_string(node);

            for(int i = 0 ; i < x.length() ; i++) {
                //add

                if(x[i] != '9') {
                    string p = x;
                    x[i] = x[i]+1;
                    int adjNode = stoi(x);
                    if(dist[adjNode] > adjNode + dist[node] && !isPrime(adjNode)) {
                        dist[adjNode] = adjNode + dist[node];
                        pq.push({adjNode + dist[node] , adjNode});
                    }
                    x = p;
                }



                //sub
                if(x[i] != '0') {
                    string p = x;
                    x[i] = x[i]-1;
                    int adjNode = stoi(x);
                    if(dist[adjNode] > adjNode + dist[node] && !isPrime(adjNode)) {
                        dist[adjNode] = adjNode + dist[node];
                        pq.push({adjNode + dist[node] , adjNode});
                    }
                    x = p;
                }

            }

            

        }
        return -1;
        
        
    }
};