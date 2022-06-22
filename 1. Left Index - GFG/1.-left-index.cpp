// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find element in sorted array

int leftIndex(int N, int arr[], int X){
    
    // Your code here
    int ans=-1;
    int low=0,high=N-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==X)
        {
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]>X)
        high=mid-1;
        else
        low=mid+1;
    }
    return ans;
    
}




// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}  // } Driver Code Ends