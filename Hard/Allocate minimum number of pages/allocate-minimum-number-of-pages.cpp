//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{   
    bool isPossible(int arr[],int n,int m,int mid){
        int count=0;
        int sum=0;
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
    //Function to find minimum number of pages.
    int findPages(int stalls[], int n, int m) 
    {
        // sort(stalls,stalls+n);
        if(m>n){
            return -1;
        }
     int low = stalls[0];
    
    int high=0;
    for(int i=0;i<n;i++){
        high+=stalls[i];
        low=max(low,stalls[i]);
        
    }
    // cout<<high<<" "<<low<<endl;
    
    int ans=    -1;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(stalls,n,m,mid)){
            ans=mid;
            high=mid-1;
            
        }
        else{
            low=mid+1;
            
        }
    }
    return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends