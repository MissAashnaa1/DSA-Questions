//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    const int mod=1e9+7;
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    
	    unordered_map<char,int>m;
	    vector<unsigned long long>dp(s.length()+1,0);
	    dp[0]=1;//empty subsequence
	    for(int i=1;i<dp.size();i++){
	        dp[i]=2*dp[i-1]%mod;
	        if(m.find(s[i-1])!=m.end()){
	            int j=m[s[i-1]];
	           dp[i]=(dp[i] - dp[j - 1] + mod) % mod;
	        }
	        
	        m[s[i-1]]=i;
	        
	    }
	    return dp[dp.size()-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends