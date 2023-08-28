//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void helper(vector<int>arr, int ind,vector<vector<int>>&ans,vector<int>curr){
        if(ind==arr.size())
           {
               ans.push_back(curr);
               return;
           }
        curr.push_back(arr[ind]);
       helper(arr,ind+1,ans,curr);
        curr.pop_back();
        helper(arr,ind+1,ans,curr);
        
        
            
    }

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& arr) {
        // Write your code here'
        sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>curr;
    helper(arr,0,ans,curr);
  set<vector<int>>s;
    for(auto it:ans)
        s.insert(it);
    ans.clear();
    for(auto it:s)
    ans.push_back(it);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends