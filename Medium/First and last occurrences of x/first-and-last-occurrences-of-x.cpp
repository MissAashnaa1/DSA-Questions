//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     int firstOcc(int arr[],int l,int h,int x,int &ans){
        if(l>h){
            return ans;
        }
        int mid=(l+h)/2;
        if(arr[mid]==x){
            ans=mid;
            return firstOcc(arr,l,mid-1,x,ans);
        }
        else if(arr[mid]<x){
            return firstOcc(arr,mid+1,h,x,ans);
        }
        else return firstOcc(arr,l,mid-1,x,ans);
    }
    int lastOcc(int arr[],int l,int h,int x,int ans){
        if(l>h){
            return ans;
        }
        int mid=(l+h)/2;
        if(arr[mid]==x){
            ans=mid;
            return lastOcc(arr,mid+1,h,x,ans);
        }
        else if(arr[mid]<x){
            return lastOcc(arr,mid+1,h,x,ans);
        }
        else return lastOcc(arr,l,mid-1,x,ans);
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int ans=-1;
        
        int first=firstOcc(arr,0,n-1,x,ans);
        ans=-1;
        int last=lastOcc(arr,0,n-1,x,ans);
        
        vector<int>v;
        v.push_back(first);
        v.push_back(last);
        return v;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends