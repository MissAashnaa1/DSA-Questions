//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void helper(vector<int>&arr,vector<vector<int> >&v,int ind,int sum,vector<int>&curr){
        if(sum==0){   
            v.push_back(curr);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(ind<i&&arr[i]==arr[i-1])
                continue;
            if(sum<0)
                break;
            curr.push_back(arr[i]);
            helper(arr,v,i+1,sum-arr[i],curr);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int> &A, int B) {
        // Write your code here'
        sort(A.begin(),A.end());
         vector<vector<int> >v;
        //  set<vector<int>>s;
         vector<int>curr;
        
         helper(A,v,0,B,curr);
         
         
        return v;
         
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends