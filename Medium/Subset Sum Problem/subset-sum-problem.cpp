//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
       bool helper(vector<int>arr, int target, int ind,vector<vector<int>>&dp,int curSum){
         if(ind>=arr.size())
            return (target==curSum); 
        // if(ind==arr.size()-1)
        //     return (target==curSum);
        
        if(target==curSum)
            return dp[ind][curSum]=true;
        // if(target<curSum)
        //     return false;
        if(dp[ind][curSum]!=-1)
            return dp[ind][curSum];
        bool take=false;
        if (target>=arr[ind]) 
        take=helper(arr,target,ind+1,dp,curSum+arr[ind]);
        bool notTake=helper(arr,target,ind+1,dp,curSum);
        return dp[ind][curSum]= take||notTake;
        
            
    }
public:

    bool isSubsetSum(vector<int>arr, int sum){
        // code here '
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        
        return helper(arr,sum,0,dp,0);
        
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends