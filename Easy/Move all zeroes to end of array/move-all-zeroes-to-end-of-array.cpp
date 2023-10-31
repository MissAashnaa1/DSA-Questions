//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int start=0;
	    int end=0;
	    while(start<=end&&end<n){
	        if(arr[start]==0&&arr[end]!=0){
	            swap(arr[start],arr[end]);
	            start++;
	            end++;
	        }
	        else if(arr[start]==0&&arr[end]==0){
	            end++;
	        }
	      
	        else {
	            start++;
	            end++;
	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends