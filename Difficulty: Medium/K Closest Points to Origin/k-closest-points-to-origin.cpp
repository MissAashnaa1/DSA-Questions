//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


    class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
       vector<pair<vector<int>, long long>> store;

    for (auto& it : points) {
        int x = it[0];
        int y = it[1];
        long long distance = (long long)x * x + (long long)y * y; 
        store.push_back({{x, y}, distance});
    }

    sort(store.begin(), store.end(), [](const pair<vector<int>, long long>& a, const pair<vector<int>, long long>& b) {
        return a.second < b.second;  
    });

    vector<vector<int>> result;
    for (int i = 0; i < k; i++) {
        result.push_back(store[i].first);
    }

    return result;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends