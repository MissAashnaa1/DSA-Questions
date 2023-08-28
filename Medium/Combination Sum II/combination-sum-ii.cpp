//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
void helper(vector<int>nums,int target,vector<vector<int>>&v,vector<int> & temp,int i,int np){
      if(target==0){
          v.push_back(temp);
          return ;
      }
      if(i==nums.size()|| target<0){
          return;
      }
      if(target<nums[i]){
          return;
      }
      if(np!=nums[i]){
          temp.push_back(nums[i]);
          helper(nums,target-nums[i],v,temp,i+1,np);
          temp.pop_back();
      }
      helper(nums,target,v,temp,i+1,nums[i]);
      
      
      
  }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here 
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>v;
        vector<int>temp;
      //  int i=0;
      int t=INT_MAX;
        helper(candidates,target,v,temp,0,t);
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