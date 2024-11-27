//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
   
int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        map<int , int>mp;
        for(int i =0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(int i =1;i<=n+1;i++){
            if(mp.find(i)  == mp.end()){
                return i;
            }
        }
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends