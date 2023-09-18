//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int N) {
        //code here
       
            vector<int> dp(N+1,0);
            for(int i=1;i<=N;i++){
                dp[i]=(i)*price[0];
            }
             
            for(int i=1;i<N;i++){
                for(int target=0;target<=N;target++){
                       int rod=i+1;
                       int notTake=dp[target];
                       int take=-1e9;
                       if(rod<=target)
                         take=  price[i]+dp[target-rod];
                       dp[target]=max(take, notTake);
                }
            }
            return dp[N];
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends