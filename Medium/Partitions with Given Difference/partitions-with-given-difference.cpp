//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
         const int mod = 1e9+7;
        int sum = 0;
        for(int i = 0 ; i< n; i++) sum += arr[i];
        sum += d;
        
        if(sum%2==1)
            return 0;
            sum/=2;
        vector<int>dp(sum+1,0);
        dp[0]+=1;
        dp[arr[0]]+=1;
        for(int i=1;i<arr.size();i++){
            vector<int>ndp(sum+1,0);
            for(int target=0;target<=sum;target++){
                
                int notTake=dp[target];
                int take=0;
                if(target>=arr[i])
                    take=dp[target-arr[i]];
                ndp[target]=(take+notTake)%mod;
            }
            dp=ndp;
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends