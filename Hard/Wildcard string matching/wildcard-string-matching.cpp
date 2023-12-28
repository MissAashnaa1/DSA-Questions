//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
   
    bool helper(string wild, string pattern,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==wild.length()&&j==pattern.length()){
            return dp[i][j]=true;
        }
        if(i==wild.length()&&j!=pattern.length()){
            return dp[i][j]=false;
        }
        if(i!=wild.length()&&j==pattern.length()){
            while(i<wild.length()&&wild[i]=='*'){
                i++;
            }
            if(i==wild.length()){
               return dp[i][j]= true;
            }
            return dp[i][j]=false;
        }
        if(wild[i]=='?'){
            return dp[i][j]=helper(wild,pattern,i+1,j+1,dp);
        }
        if(wild[i]=='*'){
            return dp[i][j]=helper(wild,pattern,i,j+1,dp)||helper(wild,pattern,i+1,j,dp);
        }
        return dp[i][j]=wild[i]==pattern[j]&&helper(wild,pattern,i+1,j+1,dp);
    }
    public:
    bool match(string wild, string pattern)
    {
        // code here
        vector<vector<int>>dp(wild.length()+1,vector<int>(pattern.length()+1,-1));
        return helper(wild,pattern,0,0,dp);
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends