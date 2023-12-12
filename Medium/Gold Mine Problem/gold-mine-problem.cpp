//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
           vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = M[i][0];
        }

        int ans = 0;
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int sum = 0, sum1 = 0, sum2 = 0;

                if (i > 0) {
                    sum = dp[i - 1][j - 1];
                }

                sum1 = dp[i][j - 1];

                if (i < n - 1) {
                    sum2 = dp[i + 1][j - 1];
                }

                dp[i][j] = M[i][j] + max(sum, max(sum1, sum2));
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }

    //     int mx=0;
    //     int dp[n][m]={0};
    //     for(int i=0;i<n;i++){
    //         dp[i][0]=M[i][0];
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=1;j<m;j++){
    //             dp[i][j]=M[i][j];
    //             int dr=0;
    //             int ur=0;
    //             int r=0;
    //             if(i>0&&j>0){
    //                 dr=dp[i-1][j-1];
    //             }
    //             if(j>0){
    //               r=dp[i][j-1];
    //             }
    //             if(i<n&&j<0){
    //                 ur=M[i+1][j-1];
    //             }
    //             dp[i][j]+=(max(max(dr,r),ur));
    //             cout<<dp[i][j]<<" ";
    //             mx=max(dp[i][j],mx);
    //         }
    //         cout<<endl;
    //     }
    //     return mx;
    // }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends