//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<ll> q;
    vector<ll> ans;
    for(ll i=0;i<K;i++) {
        if(A[i]<0)
        q.push(A[i]);
        
    }
    // ans.push_back(q.front());
    // if(q.front()==A[0])
    // q.pop();
    for(int i=K;i<N;i++) {
        if(q.empty()) {
            ans.push_back(0);
        }
        else {
            ans.push_back(q.front());
           
        }
       if(!q.empty() && A[i-K]==q.front()) {
           q.pop();
       }
        if(A[i]<0) {
            q.push(A[i]);
        } 
    }
       if(q.empty()) {
            ans.push_back(0);
        }
        else {
            ans.push_back(q.front());
           
        }
    return ans;
                                                 
 }