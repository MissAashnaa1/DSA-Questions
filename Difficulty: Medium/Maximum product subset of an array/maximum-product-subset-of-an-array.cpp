//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    const long long int mod=1e9+7;

    long long int findMaxProduct(vector<int>& arr) {
    int n = arr.size();
    long long mod = 1e9 + 7;
    long long prod = 1;
    vector<int> negatives;
    int countPositives = 0;
    int countZeros = 0;

    if (n == 1) return arr[0] % mod;  // Single element edge case

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            countZeros++;
        } else if (arr[i] < 0) {
            negatives.push_back(arr[i]);
        } else {
            countPositives++;
            prod = (prod * arr[i]) % mod;
        }
    }

    // If all elements are zero
    if (countPositives == 0 && negatives.size() == 0) return 0;

    // If all elements are negative and no zero
    if (countPositives == 0 && countZeros > 0 && negatives.size() == 1) {
        return 0;
    }

    // Sort negatives to find the smallest negative number
    sort(negatives.begin(), negatives.end());

    if (negatives.size() % 2 != 0) {
        // If odd, exclude the smallest negative number
        for (int i = 0; i < negatives.size() - 1; i++) {
            prod = (prod * negatives[i]) % mod;
        }
    } else {
        // If even, include all negative numbers
        for (int i = 0; i < negatives.size(); i++) {
            prod = (prod * negatives[i]) % mod;
        }
    }

    return (prod + mod) % mod;  // Ensure non-negative result
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends