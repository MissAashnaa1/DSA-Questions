//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
   long long int count=0;
    void merge(long long arr[],long long low, long long mid, long long high){
        long long size1 = mid-low+1;
        long long size2 = high-mid;
        long long L[size1],R[size2];
        for(long long i=0;i<size1;i++){
            L[i]=arr[i+low];
        }
        for(long long i=0;i<size2;i++){
            R[i]=arr[i+mid+1];
        }
        long long i=0,j=0,k=low;
        while(i<size1&&j<size2){
            if(L[i]<=R[j]) arr[k++]=L[i++];
            // else arr[k++]=R[j++];        
            else{
                arr[k++]=R[j++];
                count+=size1-i;
            }
        }
        while(i<size1) arr[k++]=L[i++];
        while(j<size2) arr[k++]=R[j++];
    }
    void mergeSort(long long arr[],long long low,long long high){
        if(low<high){
            long long mid=low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return count;
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends