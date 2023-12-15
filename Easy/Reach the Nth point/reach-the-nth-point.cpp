//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		      int mod=1e9+7;
            if(n==0||n==1)return 1;
            vector<int>dp(n+1,-1);
            dp[0]=1;
            dp[1]=1;
            for(int i=2;i<=n;i++){
                dp[i]=(dp[i-1]+dp[i-2])%mod;
            }
            return dp[n];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends