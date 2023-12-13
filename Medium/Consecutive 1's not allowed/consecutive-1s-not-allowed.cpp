//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	const int mod=1e9+7;
	void helper(int n,string str, ll &count){
	    if(n==0){
	        count=(count+1)%mod;
	        return ;
	    }
	    if(str[str.length()-1]=='0'){
	        helper(n-1,str+'0',count);
	        helper(n-1,str+'1',count);
	    }
	    else{
	        helper(n-1,str+'0',count);
	    }
	    
	}
	
	ll countStrings(int n) {
	    // code here
	   
	   // vector<vector<int>>dp(n,vector<int>(2,-1));
	   // helper(n-1,"1",count);
	   // helper(n-1,"0",count);
	    
	      int MOD = 1e9+7;
        long prev = 1,curr = 1;
        for(int i=2;i<=n;i++) {
            long ncurr = (prev + curr) % MOD;
            prev = curr;
            curr = ncurr; 
        }
        return (int)(prev + curr) %MOD;
    }
	   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends