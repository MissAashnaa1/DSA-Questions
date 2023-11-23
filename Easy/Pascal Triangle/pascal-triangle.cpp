//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        
       
        vector<ll> prevRow;
        
        for (int i = 0; i < n; i++) {
            vector<ll> currentRow(i + 1, 1);
            for (int j = 1; j < i; j++) {
                currentRow[j] = (prevRow[j - 1] + prevRow[j])%1000000007 ;
            }
            prevRow = currentRow;
        }

        return prevRow ;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends