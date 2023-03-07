//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
void qrev(queue<int> & q) {
    //base case
    if(q.size()==0)
    return;
    int x=q.front();
    q.pop();
    qrev(q);
    q.push(x);
    
}
queue<int> rev(queue<int> q)
{
    // add code here.
    qrev(q);
    return q;
}