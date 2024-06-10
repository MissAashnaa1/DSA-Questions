//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
                unordered_map<char, int> order = {{'!', 0}, {'#', 1}, {'$', 2}, {'%', 3}, {'&', 4}, {'*', 5}, {'?', 6}, {'@', 7}, {'^', 8}};

        sort(nuts, nuts + n, [&](char a, char b)
             { return order[a] < order[b]; });

        sort(bolts, bolts + n, [&](char a, char b)
             { return order[a] < order[b]; });
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends