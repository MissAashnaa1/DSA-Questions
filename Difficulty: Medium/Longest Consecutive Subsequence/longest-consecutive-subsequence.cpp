//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

      int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        map<int, int> mp;
        
        for(int i=0; i<n; ++i){
            mp[arr[i]]++;
        }
        
        int ans = 1;
        vector<int> v;
        
        for(auto ele: mp){
            v.push_back(ele.first);
        }
        
        int cnt = 1;
        for(int i=0; i<v.size()-1; ++i){
            if(v[i]+1==v[i+1]){
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                cnt = 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends