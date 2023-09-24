//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int> dp(n,1);
    vector<int> hash(n,0);
    vector<int>v;
    int ans = -1;
    for(int i=0;i<n;i++){
        hash[i]=i;
    }
    int last=0;
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i]){
                if(dp[i]<1+dp[prev_index]){
                    dp[i]=1+dp[prev_index];
                    hash[i]=prev_index;
                    
                }
            }
        }
        
    }
    for(int i=0;i<=n-1;i++){
        if(ans<dp[i]){
            ans=dp[i];
            last=i;
        }
    }
    
    v.push_back(arr[last]);
    while(hash[last]!=last){
        v.push_back(arr[hash[last]]);
        last=hash[last];
    }
    reverse(v.begin(),v.end());
    return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends