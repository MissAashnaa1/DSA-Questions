//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    bool isPossible(int arr[],int n,int m,long long mid){
        long long count=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
            sum+=arr[i];
            }
            else{
                count++;
                sum=arr[i];
            }
        }
        if(sum<=mid){
            count++;
        }
        if(count<=m){
            return true;
        }
            return false;
        
    }
  public:
    long long minTime(int stalls[], int n, int k)
    {
      
       
     int low = stalls[0];
    
    long long high=0;
    for(int i=0;i<n;i++){
        high+=stalls[i];
        low=max(low,stalls[i]);
        
    }
    // cout<<high<<" "<<low<<endl;
    
    long long ans=-1;
    while(low<=high){
        long long mid=(low+high)/2;
        if(isPossible(stalls,n,k,mid)){
            ans=mid;
            high=mid-1;
            
        }
        else{
            low=mid+1;
            
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends