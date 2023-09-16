//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	            int sum=accumulate(arr,arr+n,0);  
        
        vector<bool>prev(sum+1,false);
        if(arr[0]<=sum)
        prev[arr[0]]=true;
        prev[0]=true;
        vector<bool>curr(sum+1,false);
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            curr[0]=true;
            for(int target=1;target<=sum;target++){
            
                bool take=false;
                if(target>=arr[i])
                    take=prev[target-arr[i]];
                bool notTake=prev[target];
                curr[target]=take||notTake;
                

            }
            prev=curr;
        }
        for(int target=0;target<=sum/2;target++){
            if(prev[target])
            mini=min(mini,abs((sum-target)-target));
        }
             
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends