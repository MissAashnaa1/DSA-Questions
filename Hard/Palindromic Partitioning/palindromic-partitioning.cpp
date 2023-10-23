//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
     bool isPall(string s, int low, int high)
    {
        while(low <= high)
        {
            if(s[low++] != s[high--])
            return 0;
        }
        return 1;
    }
    int fun(string &str,int i,vector<int> &dp){
        if(i >= str.size()) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        
        for(int left=i;left<str.size();left++){
            if(isPall(str,i,left))
    ans=min(ans,1+fun(str,left+1,dp));
            
        }
        return dp[i]=ans;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        vector<int>dp(str.length(),-1);
        return fun(str,0,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends