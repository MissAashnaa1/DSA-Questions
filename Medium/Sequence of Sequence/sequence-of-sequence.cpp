//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
         int solve(int m,int n)
    {
        if(n>m)
        return 0;
        if(n==0)
        return 1;
        return solve(m/2,n-1)+solve(m-1,n);
    }
    int numberSequence(int m, int n){
        solve(m,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends