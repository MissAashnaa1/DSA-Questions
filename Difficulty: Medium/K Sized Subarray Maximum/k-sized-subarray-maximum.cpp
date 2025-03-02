//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        int currmax = *max_element(arr.begin(),arr.begin() + k), r=1;
        while(r <= arr.size() - k +1){
            int l = *(arr.begin()+r-1);
            int n = *(arr.begin()+r+k-1);
            res.push_back(currmax);
            if(currmax == l){
                currmax = *max_element(arr.begin() + r,arr.begin() + r + k);
            }
            else{
                currmax = max(currmax, n);
            }
            r++;
        }   
        return res; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends