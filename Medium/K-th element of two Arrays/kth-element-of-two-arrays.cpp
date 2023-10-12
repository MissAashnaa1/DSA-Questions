//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n1, int n2, int k)
    {
        
        if(n1>n2){
            return kthElement(nums2,nums1,n2,n1,k);
        }
        
        int low=max(0,k-n2);
        int high=min(n1,k);
        while(low<=high){
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            int mid1=(low+high)/2;
            int mid2=k-mid1;
            if(mid1>0){
                l1=nums1[mid1-1];
            
            }
            if(mid2>0){
                l2=nums2[mid2-1];
            }
            if(mid1<n1){
                r1=nums1[mid1];
                
            }
            if(mid2<n2){
                r2=nums2[mid2];
            }
            if(l1<=r2&&l2<=r1){
                return max(l1,l2);
                
            }
            else if(l2>r1){
                low=mid1+1;
            }
            else {
                high=mid1-1;
            }
           
        }
        return -1;

    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends