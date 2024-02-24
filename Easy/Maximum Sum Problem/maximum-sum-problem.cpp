//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        
            //code here.
              int solve(int n)
        {
            // pruning // base
            if(n<=0)
            {
                return 0;
            }
            //cache
          
            // mathematics
            int ans=n;
            int a=solve(n/2);
            int b=solve(n/3);
            int c=solve(n/4);
            ans=max(ans,a+b+c);
            // return and save
            return ans;
        }
        int maxSum(int n)
        {
            return solve(n);
        
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends