//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    int dp[1001][1001];
 
  int longestsubsequence(string &s1,string &s2, int i,int j) {
        if(i==0||j==0)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(s1[i-1]==s2[j-1])
        return dp[i][j]=1+longestsubsequence(s1,s2,i-1,j-1);
        
        return dp[i][j]=max(longestsubsequence(s1,s2,i-1,j),longestsubsequence(s1,s2,i,j-1));
        
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.size();
        dp[n][n];
        memset(dp, -1, sizeof(dp));
       string s1=S;
       reverse(s1.begin(),s1.end());
       int k=longestsubsequence(S,s1,n,n);
       
       return n-k;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends