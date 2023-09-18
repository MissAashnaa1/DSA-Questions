//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int cap, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int>prev(cap+1,0);
       for(int i=wt[0];i<=cap;i++){
           prev[i]=val[0];
       }
       for(int i=1;i<n;i++){
           vector<int>curr(cap+1,0);
               for(int target=1;target<=cap;target++){
                   int notTake=prev[target];
                   int take=INT_MIN;
                   if(target>=wt[i])
                       take=val[i]+prev[target-wt[i]];
                   
                   curr[target]=max(take,notTake);
               }
            prev=curr;
           
       }
       return prev[cap];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends