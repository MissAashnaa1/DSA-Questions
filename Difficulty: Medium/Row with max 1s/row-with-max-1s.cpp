//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
     int rowWithMax1s(vector<vector<int>>& a) {
        int maxi = 0, ans = -1;
        for (int i = 0; i < a.size(); i++) {
            int p = upper_bound(a[i].begin(), a[i].end(), 0) - a[i].begin();
            if (maxi < a[0].size() - p) {
                ans = i;
                maxi = a[0].size() - p;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends